#ifndef FOOD_HPP
#define FOOD_HPP

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


// #include "Simulation.hpp"
#include "bsp.hpp"

#include "s_data.hpp"
#include "s_particule.hpp"

class	Food
{
	private:
		std::vector<s_particule *>	particules;

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
		void			drawAllFood( sf::RenderWindow& win );
		void			getsEaten( void );

		void			buildCheckPointsCr( float x, float y );
		void			buildCheckPointsSe( float x, float y );
		void			drawCheckPoints( sf::RenderWindow& win );
};

#endif
