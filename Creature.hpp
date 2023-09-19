#include <iostream>
#include <chrono>

#include "Fixed.hpp"

class	Creature
{
	private :
		std::chrono::seconds	_lifeTime;
		size_t					_fitness;
		Fixed					_gradientDescent;
		Fixed					_speed;
		Fixed					_size;

	public :
		Creature( void );
		~Creature( void );

		
}
