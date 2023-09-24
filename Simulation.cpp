/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(5), _timeToDie(10),
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


// void	Simulation::printTimeToDie( void )
// {
// 	std::cout << "Time to die == " << this->_timeToDie << std::endl;
// 	return ;
// }

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

}
