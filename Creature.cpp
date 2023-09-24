#include <iostream>

#include "Creature.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
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
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();

	return (t - this->_birthTime >= _timeToDie);
}
