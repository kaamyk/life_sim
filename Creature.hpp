#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <chrono>

#include "Fixed.hpp"

class	Creature
{
	private :
		unsigned int			_index;
		std::chrono::seconds	_lifeTime;
		unsigned int			_fitness;
		Fixed					_gradientDescent;
		Fixed					_speed;
		Fixed					_size;

	public :
		Creature( void );
		~Creature( void );

		bool	checkTime( std::chrono::seconds const _timeToDie );		
};

#endif
