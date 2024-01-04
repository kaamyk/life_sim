#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation.hpp"

class	Food
{
	private:
		unsigned int	_position[2];
		sf::Texture		_foodTexture;
		sf::Sprite		_foodSprite;

	public:
		Food( void );
		~Food( void );

		unsigned int	getPosition( bool xy );
		void			setPosition( unsigned int x, unsigned int y );

		template<typename T>
		bool			checkPosition( T x, T y ){
			T	_creaturePosx[] = {x - static_cast<T>(data.creatureSize / 2), x + static_cast<T>(data.creatureSize / 2)};
			T	_creaturePosy[] = {y - static_cast<T>(data.creatureSize / 2), y + static_cast<T>(data.creatureSize / 2)};
			unsigned int _foodPosx[] = {_position[0] - (data.foodSize / 2), _position[0] + (data.foodSize / 2)};
			unsigned int _foodPosy[] = {_position[1] - (data.foodSize / 2), _position[1] + (data.foodSize / 2)};

			if ( (_creaturePosx[0] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1])
				|| (_creaturePosx[1] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1]) )
			{
				if ( (_creaturePosy[0] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosx[1])
				|| (_creaturePosy[1] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosy[1]) )
				{
					return (1);
				}
			}
			return (0);
		}
		void			drawFood( sf::RenderWindow& win, assetManager& _assets );
		unsigned int*	getCoordinates( void );
};

#endif
