#include <iostream>

#include "Creature.hpp"

Creature::Creature( void ): _lifeTime(0), _fitness(0),
							_gradientDescent(0),
							_speed(rand() % 100),
							_size(rand() % 100)
{
	std::cout << "Constructor Creature" << std::endl;
	Simulation::updateNbCreature( 1 );
	return ;
}

// Creature::Creature( Creature &Parent )
// {
	
// }

Creature::~Creature( void )
{
	return ;
}

Creature::die( Simulation& Simulation, std::vector::iterator i )
{
	Simulation.updateNbCreature(0);
	Simulation.eraseCreature(i);
	return ;	
}

Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	return (this->_lifetime >= _timeToDie)
}
