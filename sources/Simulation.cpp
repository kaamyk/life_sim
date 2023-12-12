/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "../includes/Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(5), _timeToDie(10),
								_nbCreature(0), _nbFood(NBFOOD)
{
	for(size_t i = 0; i < _nbFood; ++i){
		_food.push_back(new Food());
	}
	return ;
}

Simulation::~Simulation( void )
{
	for(std::vector<Food *>::iterator i = _food.begin(); i != _food.end(); ++i){
		delete *i;
		_food.erase(i);
	}
	for(std::vector<Creature *>::iterator i = _population.begin(); i != _population.end(); ++i){
		delete *i;
		_population.erase(i);
	}
	return ;
}

void			Simulation::loadTextures( void )
{
	_assets.createNewTexture("./images/creature.png");
	_assets.createNewTexture("./images/foodParticule.png");
	_assets.createNewTexture("./images/sensorRayOFF.png");
	_assets.createNewTexture("./images/sensorRayON.png");
}

unsigned int	Simulation::giveIndex( void ){ return ( this->_nbCreature ); }

std::vector<Food *> const&		Simulation::getFood( void ){ return (_food); }
void	Simulation::foodGetsEaten( std::vector<Food *>::iterator const& i ){
	(*i)->setPosition(rand() % WIN_L, rand() % WIN_H);
}

void	Simulation::createNewCreature( void )
{
	try{
		_population.push_back(new Creature(WIN_H, WIN_L));
		updateNbCreature( 1 );
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

bool	Simulation::checkNbCreature( void ){ return (_population.size() != 0); }

void	Simulation::updateNbCreature( bool a ){ a ? ++(this->_nbCreature) : --(this->_nbCreature); }

void	Simulation::checkLifeTimes( void )
{
	if (_population.size() == 0)
		return;
	for(std::vector<Creature *>::iterator i = _population.begin(); i != _population.end() && !_population.empty(); ++i)
	{
		if ((*i)->checkTime(this->_timeToDie)){
			this->_population.erase(i);
			this->updateNbCreature(0);
			i = _population.begin();
		}
	}
	return ;
}

void	printSensors(const std::vector<float> sensorInputs, size_t i){
	std::cout << "Creature[" << i << "] Sensors => ["
		<< sensorInputs[0] << ", "
		<< sensorInputs[1] << ", "
		<< sensorInputs[2] << "]" << std::endl;
}

void	printControls(std::vector<float> outputs, size_t i){
	std::cout << "Creature[" << i << "] controls => ["
		<< outputs[0] << ", "
		<< outputs[1] << ", "
		<< outputs[2] << ", "
		<< outputs[3] << "]" << std::endl;
}

void	Simulation::drawPopulation( sf::RenderWindow& win )
{
	std::cout << "-------------------" << std::endl;
	// std::cout << "population.size() == " << _population.size() << std::endl;
	if (_population.size() == 0)
		return;
	for (size_t i = 0; i < _population.size(); ++i)
	{
		const std::vector<float> sensorInputs = _population[i]->getSensor()->getState();
		printSensors(sensorInputs, i);
		std::vector<float>	outputs = _population[i]->feedForward(sensorInputs);
		printControls(outputs, i);

		for (__uint8_t j = 0; j < 4; ++j){
			if (outputs[j])
				_population[i]->move(j);
		}
		std::vector<Food *>::iterator	it = _food.begin();
		_population[i]->eat(_food, it); 
		if(it != _food.end()){
			std::cout << "food.it == " << it - _food.begin() << std::endl;
			foodGetsEaten(it);
		}
		_population[i]->drawCreature(win, _assets, *this);
		std::cout << std::endl;
	}
	return ;
}

void	Simulation::drawAllFood( sf::RenderWindow& win )
{
	for (unsigned int i = 0; i < _nbFood; ++i)
		_food[i]->drawFood(win, _assets);
}