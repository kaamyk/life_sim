#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Fixed.hpp"

class	Creature
{
	private :
		unsigned int	_index;
		unsigned int	_fitness;
		Fixed			_gradientDescent;
		Fixed			_speed;
		Fixed			_size;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		sf::Texture		_creatureTexture;
		sf::Sprite		_creatureSprite;

	public :
		Creature( void );
		~Creature( void );

		bool	checkTime( std::chrono::seconds const _timeToDie );
		void	drawCreature( sf::RenderWindow& win, sf::Texture& texture );
};

#endif
