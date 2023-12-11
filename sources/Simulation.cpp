/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "../includes/Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(5), _timeToDie(30),
								_nbCreature(0), _nbFood(NBFOOD)
{
	return ;
}

Simulation::~Simulation( void )
{
	return ;
}

void			Simulation::loadTextures( void )
{
	_assets.createNewTexture("./images/creature.png");
	_assets.createNewTexture("./images/foodParticule.png");
	_assets.createNewTexture("./images/sensorRayOFF.png");
	_assets.createNewTexture("./images/sensorRayON.png");
}

unsigned int	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
}

Food*		Simulation::getFood( void )
{
	return (&_food[0]);
}

void	Simulation::createNewCreature( void )
{
	// Creature	newCreature(WIN_H, WIN_L);
	// std::string	path("./images/creature.png");

	try{
		_population.push_back(new Creature(WIN_H, WIN_L));
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	updateNbCreature( 1 );
	return ;
}

bool	Simulation::checkNbCreature( void )
{
	return (this->_nbCreature != 0);
}

void	Simulation::updateNbCreature( bool a )
{	
	a ? ++(this->_nbCreature) : --(this->_nbCreature);
	return ;
}

void	Simulation::checkLifeTimes( void )
{
	if (_population.size() == 0)
		return;
	for(std::vector<Creature *>::iterator i = _population.begin(); i != _population.end(); ++i)
	{
		if ((*i)->checkTime(this->_timeToDie))
		{
			std::cout << "In if erase()" << std::endl;
			this->updateNbCreature(0);
			this->_population.erase(i);
		}
	}
	return ;
}

void	Simulation::drawPopulation( sf::RenderWindow& win )
{
	std::cout << "population.size() == " << _population.size() << std::endl;
	if (_population.size() == 0)
		return;
	for (size_t i = 0; i < _population.size(); ++i)
	{
		const std::vector<float> sensorInputs = _population[i]->getSensor()->getState();
		std::vector<float>	outputs = _population[i]->feedForward(sensorInputs);

		std::cout << "Creature[" << i << "] controls => ["
		<< outputs[0] << ", "
		<< outputs[1] << ", "
		<< outputs[2] << ", "
		<< outputs[3] << "]" << std::endl;

		if (outputs[0])
			_population[i]->moveUp();
		if (outputs[1])
			_population[i]->moveDown();
		if (outputs[2])
			_population[i]->moveRight();
		if (outputs[3])
			_population[i]->moveLeft();
		_population[i]->drawCreature(win, _assets, *this);
	}
	return ;
}

void	Simulation::drawAllFood( sf::RenderWindow& win )
{
	for (unsigned int i = 0; i < _nbFood; ++i)
		_food[i].drawFood(win, _assets);
	return ;
}
