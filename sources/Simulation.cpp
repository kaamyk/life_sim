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
}

unsigned int	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
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
		i->setTarget(_food);
		if (i->checkTarget())
			i->moveToTarget();
		else
			i->moveRandom( WIN_L, WIN_H );
		i->drawCreature(win, _assets);
	}
	return ;
}

void	Simulation::drawAllFood( sf::RenderWindow& win )
{
	for (unsigned int i = 0; i < _nbFood; ++i)
		_food[i].drawFood(win, _assets);
	return ;
}
