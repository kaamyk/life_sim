#include <iostream>

#include "Creature.hpp"

Creature::Creature( void ): _lifeTime(0), _fitness(0),
							_gradientDescent(0),
							_speed(rand() % 100),
							_size(rand() % 100)
{
	return ;
}

Creature::Creature( Creature &Parent)
{
	
}

Creature::~Creature( void )
{
	return ;
}
