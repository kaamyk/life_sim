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
		bool			_isSpecial;

	public:
		Food( void );
		Food( bool special );
		~Food( void );

		bool const &	getIsSpecial( void );
		unsigned int*	getCoordinates( void );
		unsigned int	getPosition( bool xy );
		void			setPosition( unsigned int x, unsigned int y );

		bool			checkPosition( float x, float y );
		void			drawFood( sf::RenderWindow& win, assetManager& _assets );
		void			getsEaten( void );
};

#endif
