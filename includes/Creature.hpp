#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Fixed.hpp"
#include "assetManager.hpp"
#include "Food.hpp"

class	Creature
{
	private :
		unsigned int	_index;
		unsigned int	_fitness;
		Fixed			_gradientDescent;
		Fixed			_position[2];
		unsigned int	_target[2];
		Fixed			_rotation;
		Fixed			_speed;
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
		void	setTarget( Food food[10] );
		bool	checkTarget( void );
		void	moveToTarget( void );
		void	moveRandom( unsigned int win_l, unsigned int win_h );
};

#endif
