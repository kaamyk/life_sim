#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "assetManager.hpp"

class	Food
{
	private:
		unsigned int	_position[2];
		sf::Texture		_foodTexture;
		sf::Sprite		_foodSprite;

	public:
		Food( void );
		~Food( void );

		bool	checkPosition(unsigned int x, unsigned int y);
		void	drawFood( sf::RenderWindow& win, assetManager& _assets );
		unsigned int*	getCoordinates( void );
};

#endif
