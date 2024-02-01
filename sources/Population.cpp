#include "../includes/Population.hpp"

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
		}
		else{
			(*i)->eat(win, _food, getPopulation());
			// (*i)->eat(win, _food, *this);
			(*i)->\
			drawCreature\
			(win,\
			 *this);
		}
	}
}