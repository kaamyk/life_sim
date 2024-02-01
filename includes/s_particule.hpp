#ifndef PARTICULE_HPP
#define PARTICULE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

struct s_particule {
	sf::Vector2f		position;
	bool				_isSpecial;
	std::array<sf::RectangleShape, 4>	foodVrt;
	sf::RectangleShape	sensPt;
	sf::RectangleShape	PtPosFo;
};

#endif