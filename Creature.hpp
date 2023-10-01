#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Fixed.hpp"
#include "assetManager.hpp"

class	Creature
{
	private :
		unsigned int	_index;
		unsigned int	_fitness;
		Fixed			_gradientDescent;
		size_t			_position[2];
		Fixed			_rotation;
		size_t			_speed;
		Fixed			_size;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		sf::Texture		_creatureTexture;
		sf::Sprite		_creatureSprite;

	public :
		Creature( void );
		Creature( size_t const win_h, size_t const win_l );
		~Creature( void );

		bool	checkTime( std::chrono::seconds const _timeToDie );
		void	drawCreature( sf::RenderWindow& win, assetManager& _assets );
		void	move( size_t win_l, size_t win_h );
};

#endif
