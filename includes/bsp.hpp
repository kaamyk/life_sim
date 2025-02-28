#ifndef BSP
#define BSP

#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


void    ft_abs( float &N );
float   getArea( sf::Vector2f P1, sf::Vector2f P2, sf::Vector2f P3 );
bool    bsp( sf::Vector2f CrSize, std::array<sf::Vector2f, 4>& vtx, sf::Vector2f const P );

#endif