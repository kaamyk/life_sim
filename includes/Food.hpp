#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "s_data.hpp"

// #include "Simulation.hpp"
#include "Particule.hpp"


class Particule;

class	Food
{
	private:
		std::vector<Particule *>	_particules;

	public:
		Food( void );
		Food( bool special );
		~Food( void );

		bool const &	getIsSpecial( void );
		sf::Vector2f const&	 	getPosition( void );
		void			setPosition( sf::Vector2f const& np );

		bool			checkPositionSe( float x, float y );
		bool			checkPositionCr( std::array<sf::RectangleShape, 4> const& pt );
		bool			checkPositionCr1( sf::Vector2f CrSize, std::array<sf::RectangleShape, 4>& CrVrt );
		void			drawFood( sf::RenderWindow& win );
		bool			getsEaten( std::vector<Particule *>::iterator& itFood );

		bool*			checkPositionCr( sf::Vector2f crSize, std::array<sf::Vector2f, 4>& crVrt );
		void			buildCheckPointsSe( float x, float y );
		void			drawCheckPoints( sf::RenderWindow& win );
};

#endif
