/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "../includes/Simulation.hpp"

Simulation::Simulation( void ){
	for(size_t i = 0; i < data.nbFood; i++){
		_food.push_back(new Food(i % 5 == 0));
	}
	for(unsigned int i = 0; i < data.nbCreature; i++){
		createNewCreature();
	}
	return ;
}

Simulation::~Simulation( void )
{
	for(std::vector<Food *>::iterator i = _food.begin(); i < _food.end(); i++){
		delete *i;
	}
	_food.clear();
	for(std::vector<Creature *>::iterator i = _population.begin(); i < _population.end(); i++){
		delete *i;
	}
	_population.clear();
	return ;
}

void			Simulation::loadTextures( void ){
	_assets.createNewTexture("./images/SquareCreature.png");
	_assets.createNewTexture("./images/SquareFood.png");
	_assets.createNewTexture("./images/SquareSpecialFood.png");
	_assets.createNewTexture("./images/sensorRayOFF.png");
	_assets.createNewTexture("./images/sensorRayON.png");
}

void			Simulation::printData( void ){
	for (unsigned int i = 0; i < _population.size(); i++){
		std::vector<Level *>& tmpBrain(_population[i]->getBrain().getLevels());
		std::cout << "Creature["<< i << "]:" << std::endl;
		for (unsigned int j = 0; j < tmpBrain.size(); ++j){
			std::vector<float>&	inputs = tmpBrain[j]->getInputs();
			std::vector<float>&	outputs = tmpBrain[j]->getOutputs();
			std::vector<float>&	biases = tmpBrain[j]->getBiases();
			(void)inputs;
			(void)outputs;
			(void)biases;

			std::cout << "\tInputs: ";
			std::cout << "\t\tinputs.size() == " << outputs.size() << std::endl;
			// for (unsigned int k = 0; k < inputs.size(); ++k){
			// 	std::cout << inputs[k];
			// }
			std::cout << std::endl;
			std::cout << "\tOutputs ";
			std::cout << "\t\toutputs.size() == " << outputs.size() << std::endl;
			// for (unsigned int k = 0; k < outputs.size(); ++k){
			// 	std::cout << outputs[k];
			// }
			std::cout << "\tBiases: ";
			std::cout << "\t\tbiases.size() == " << outputs.size() << std::endl;
			// for (unsigned int k = 0; k < biases.size(); ++k){
			// 	std::cout << biases[k];
			// }
			std::cout << std::endl;
		}
	}
}

std::vector<Food *> const&		Simulation::getFood( void ){
	return (_food);
}

std::vector<Creature *>&		Simulation::getPopulation( void ){
	return (_population);
}

bool	Simulation::checkNbCreature( void ){
	return (_population.size() != 0);
}

size_t	Simulation::getPopulationSize( void ){
	return (_population.size());
}

void	Simulation::checkLifeTimes( void ){
	if (_population.size() == 0)
		return;
	for(std::vector<Creature *>::iterator i = _population.begin();  !_population.empty() && i != _population.end(); ++i)
	{
		if ((*i)->checkTime(data.timeToDie)){
			delete *i;
			this->_population.erase(i);
			i = _population.begin();
		}
	}
}

void	Simulation::createNewCreature( void ){
	try{
		_population.push_back(new Creature());
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

void	Simulation::createMutatedCreature( NeuralNetwork* brain ){
	NeuralNetwork* n_brain = new NeuralNetwork(brain);
	Creature* n_creature = new Creature(n_brain);
	
	_population.push_back(n_creature);
}

bool	Simulation::creatureMove( Creature* Cr, __uint8_t i ){
	// std::vector<float>	outputs = Cr->feedForward(Cr->getSensor()->getState());

	std::vector<float>	outputs;
	switch (i){
		case 0:
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			break;
		case 1:
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			break;
		case 2:
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			break;
		case 3:
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			break;
		case 4:
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			break;
		case 5:
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			break;
		case 6:
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			break;
		case 7:
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			outputs.push_back(0.0f);
			outputs.push_back(1.0f);
			break;
		default:
			outputs = Cr->feedForward(Cr->getSensor()->getState());
			break;
	}

	for (__uint8_t j = 0; j < 4; ++j){
		if (outputs[j]){
			Cr->move(j);
		}
	}
	Cr->updatePosition();
	if (Cr->checkLastPositions())
		return (1);
	return (0);
}

void	Simulation::updatePopulation( sf::RenderWindow& win ){
	for (std::vector<Creature *>::iterator i = _population.begin(); i < _population.end(); i++){
	// std::cout << "Creature position: {" << (*i)->getPosition().x << ", " << (*i)->getPosition().y << "}" << std::endl;
		if(creatureMove(*i, std::distance(_population.begin(), i))){
			std::cout << "Creature erased" << std::endl;
			delete (*i);
			_population.erase(i);
			i = _population.begin();
			continue;
		}
		if (*i){
			(*i)->eat(win, _food, getPopulation());
			// (*i)->eat(win, _food, *this);
			(*i)->drawCreature(win, *this);
		}
	}
}

void	Simulation::drawAllFood( sf::RenderWindow& win ){
	for (std::vector<Food *>::iterator i = _food.begin(); i != _food.end(); i++){
		(*i)->drawFood(win);
	}
}