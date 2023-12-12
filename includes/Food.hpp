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
		bool			checkPosition( T x, T y){
		return (x >= _position[0] - 10 && x <= _position[0] + 10 && y >= _position[1] - 10 && y <= _position[1] + 10 );
	}
		void			drawFood( sf::RenderWindow& win, assetManager& _assets );
		unsigned int*	getCoordinates( void );
};

#endif
