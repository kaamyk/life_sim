#ifndef PARTICULE_HPP
#define PARTICULE_HPP

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "s_data.hpp"

#include "bsp.hpp"

class	Particule{
	private:
	sf::Vector2f		_position;
	bool				_isSpecial;
	sf::RectangleShape	_sprite;
	std::array<sf::RectangleShape, 4>	_partVtx;
	sf::RectangleShape	_sensorPt;
	sf::RectangleShape	_checkPos;

	public:
		Particule( void );
		~Particule( void );

		Particule& operator=( Particule const& src );

		bool const&			getIsSpecial( void ) const;
		sf::Vector2f const&	getPosition( void ) const;

		bool	checkPositionSe( float x, float y );
		bool	checkPositionCr( sf::Vector2f crSize, std::array<sf::Vector2f, 4>& checkpointsPos );

		void	setColorParticule( void );
		void    drawParticule( sf::RenderWindow& win );
};

#endif