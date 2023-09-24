#include <iostream>

#include "Creature.hpp"

Creature::Creature( void ): _lifeTime(0), _fitness(0),
							_gradientDescent(0),
							_speed(rand() % 100),
							_size(rand() % 100)
{
	std::cout << "Constructor Creature" << std::endl;
	return ;
}

Creature::~Creature( void )
{
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	return (this->_lifeTime >= _timeToDie);
}
