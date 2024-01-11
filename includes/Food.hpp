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

		std::vector<sf::RectangleShape>	r;


	public:
		Food( void );
		Food( bool special );
		~Food( void );

		bool const &	getIsSpecial( void );
		unsigned int*	getCoordinates( void );
		unsigned int	getPosition( bool xy );
		void			setPosition( unsigned int x, unsigned int y );

		bool			checkPositionSe( float x, float y );
		bool			checkPositionCr( float x, float y, float r );
		void			drawFood( sf::RenderWindow& win, assetManager& _assets );
		void			getsEaten( void );

		void			buildCheckPoints(float crPosX[2], float crPosY[2], float foPosX[2], float foPosY[2]);
		void			buildCheckPoints(float x, float y, float foPosX[2], float foPosY[2]);
		void			drawCheckPoints( sf::RenderWindow& win );
};

#endif
