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

		std::array<sf::RectangleShape, 4>	foodVrt;
		std::vector<sf::RectangleShape>	sensPt;


	public:
		Food( void );
		Food( bool special );
		~Food( void );

		bool const &	getIsSpecial( void );
		sf::Vector2f const&	 	getPosition( void );
		void			setPosition( sf::Vector2f np );

		bool			checkPositionSe( float x, float y );
		bool			checkPositionCr( std::array<sf::RectangleShape, 4> const& pt );
		void			drawFood( sf::RenderWindow& win );
		void			getsEaten( void );

		void			buildCheckPoints( float crPosX[2], float crPosY[2], float foPosX[2], float foPosY[2] );
		void			buildCheckPoints( float x, float y );
		void			drawCheckPoints( sf::RenderWindow& win );
};

#endif
