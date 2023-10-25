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
								_nbCreature(0), _nbFood(10)
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
	Creature	newCreature(WIN_H, WIN_L);
	std::string	path("./images/creature.png");

	this->_population.push_back(newCreature);
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
	for(std::vector<Creature>::iterator i = _population.begin(); i != _population.end() && _population.size() != 0; ++i)
	{
		if (i->checkTime(this->_timeToDie))
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
	for (std::vector<Creature>::iterator i = _population.begin(); i != _population.end() && _population.size() != 0; ++i)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			i->moveUp();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			i->moveDown();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			i->moveRight();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			i->moveLeft();
		i->drawCreature(win, _assets, *this);
	}
	return ;
}

void	Simulation::drawAllFood( sf::RenderWindow& win )
{
	for (unsigned int i = 0; i < _nbFood; ++i)
		_food[i].drawFood(win, _assets);
	return ;
}
