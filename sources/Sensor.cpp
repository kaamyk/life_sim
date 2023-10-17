#include "../includes/Sensor.hpp"
#include <cmath>

Sensor::Sensor( void ): _rayCount(3), _rayLenght(50 + 20),
						_raySpread(Fixed(3.14159265359f) / 4)		
{
	_rays = new unsigned int**[_rayCount];
	// _raySprite = {sf::Vertex(sf::Vector2f(10.f, 10.f)), sf::Vertex(sf::Vector2f(150.f, 150.f))};
	_raySprite[0] = sf::Vertex(sf::Vector2f(10.f, 10.f));
	_raySprite[1] = sf::Vertex(sf::Vector2f(150.f, 150.f));
	for(unsigned int i = 0; i < 4; ++i)
	{
		_rays[i] = new unsigned int*[2];
		_rays[i][0] = new unsigned int[2];
		_rays[i][1] = new unsigned int[2];
	}
	return ;
}

Sensor::~Sensor( void )
{
	for(unsigned int i = 0; i < _rayCount; ++i)
	{
		delete _rays[i][0];
		delete _rays[i][1];
	}
	delete [] _rays;
	return ;
}

// void	update( Creature c )
// {
// 	for (unsigned int i = 0; i < _rayCount; ++i)
// 	{
// 		unsigned int rayAngle = Simulation::lerp(_raySpread / 2, -(_raySpread / 2), i / (_rayCount - 1));
// 		unsigned int _rays[i][0] = {c.getCoordinates(0), c.getCoordinates(1)};
// 		unsigned int _rays[i][1] = {c.getCoordinates[0] - sin(rayAngle) * _rayLenght,c.getCoordinates[1] - cos(rayAngle) * _rayLenght};
// 	}
// }

// void	drawRay( sf::RenderWindow& win )
// {
// 	win.draw(line, 2, sf::Lines);
// 	return ;
// }
