#ifndef BSP
#define BSP

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


void    ft_abs( float &N );
float   getArea( sf::Vector2f P1, sf::Vector2f P2, sf::Vector2f P3 );
bool    bsp( sf::Vector2f CrSize, std::array<sf::RectangleShape, 4>& vrtx, sf::Vector2f const P );

#endif