#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Simulation.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

class	Food
{
	private:
		// sf::Vector2f	_position;
		// sf::Texture		_foodTexture;
		// sf::Sprite		_foodSprite;
		sf::RectangleShape	_foodSprite;
		bool			_isSpecial;

		std::vector<sf::RectangleShape>	r;


	public:
		Food( void );
		Food( bool special );
		~Food( void );

		bool const &	getIsSpecial( void );
		sf::Vector2f const&	 	getPosition( void );
		void			setPosition( sf::Vector2f np );

		bool			checkPositionSe( float x, float y );
		bool			checkPositionCr( sf::RectangleShape const& R );
		void			drawFood( sf::RenderWindow& win, assetManager& _assets );
		void			getsEaten( void );

		void			buildCheckPoints(float crPosX[2], float crPosY[2], float foPosX[2], float foPosY[2]);
		void			buildCheckPoints(float x, float y, float foPosX[2], float foPosY[2]);
		void			drawCheckPoints( sf::RenderWindow& win );
};

#endif
