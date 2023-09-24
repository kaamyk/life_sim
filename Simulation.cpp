/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(10), _timeToDie(10),
								_nbCreature(0)
{
	return ;
}

Simulation::~Simulation( void )
{
	return ;
}

unsigned int	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
}


void	Simulation::createNewCreature( void )
{
	Creature	newCreature;

	_population.push_back(newCreature);
	updateNbCreature( 1 );
	return ;
}

bool	Simulation::checkNbCreature( void )
{
	return (this->_nbCreature > 0);
}

void	Simulation::updateNbCreature( bool a )
{
	if (a)
		++(this->_nbCreature);
	else
		--(this->_nbCreature);
	return ;
}

void	Simulation::eraseCreature( std::vector<Creature>::iterator i)
{
	this->_population.erase(i);
	return ;
}

void	Simulation::checkLifeTimes( void )
{
	for(std::vector<Creature>::iterator i = _population.begin(); i != _population.end(); ++i)
		if (i->checkTime(this->_timeToDie))
		{
			this->updateNbCreature(0);
			this->eraseCreature(i);
		}

}
