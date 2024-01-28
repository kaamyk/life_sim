#include "../includes/Sensor.hpp"
#include "../includes/Simulation.hpp"
#include <cmath>

Sensor::Sensor( void ): _rayCount(3), _rayLenght(100),
						_rayAngle(30)
{
	// _rays = new unsigned int**[_rayCount];
	// for(unsigned int i = 0; i < _rayCount; ++i)
	// {
	// 	_rays[i] = new unsigned int*[2];
	// 	_rays[i][0] = new unsigned int[2];
	// 	_rays[i][1] = new unsigned int[2];
	// 	_state.push_back(0);
	// }
	// // std::cout<< "In constructor:" << std::endl;
	for (__uint8_t i = 0; i < _rayCount; i++){
		_state.push_back(0);
	}
	ptcheck = sf::RectangleShape(sf::Vector2f(5, 5));
	ptcheck.setFillColor(sf::Color::Green);
	ptcheck.setOrigin(2.5f, 2.5f);
	return ;
}

Sensor::~Sensor( void )
{
	// delete [] _rays;
	return ;
}



bool	Sensor::findIntersection( sf::RenderWindow& win, sf::RectangleShape* r, int rayRotation, Creature& c, std::vector<Food *> const& food )
{
	double	pt[2];

	r->setSize(sf::Vector2f(1, _rayLenght));
	r->setRotation( rayRotation + 180 );
	r->setPosition (c.getPosition().x, c.getPosition().y);

	if (rayRotation < 0)
		rayRotation += 360;
	else if (rayRotation >= 360)
		rayRotation -= 360;
	for (unsigned int i = 0; i < data.nbFood; ++i)
	{
		if (food[i]->getPosition().x < c.getPosition().x + _rayLenght && food[i]->getPosition().x > c.getPosition().x - _rayLenght
			&& food[i]->getPosition().y < c.getPosition().y + _rayLenght && food[i]->getPosition().y > c.getPosition().y - _rayLenght)
		{
			pt[0] = c.getPosition().x;
			pt[1] = c.getPosition().y;
			ptcheck.setPosition(c.getPosition());
			for(unsigned int j = 0; j < _rayLenght; ++j)
			{
				pt[0] = pt[0] + sin(rayRotation * (3.14159265359f / 180.0f));
				pt[1] = pt[1] - cos(rayRotation * (3.14159265359f / 180.0f));
				if (food[i]->checkPositionSe(pt[0], pt[1])){
					food[i]->drawCheckPoints(win);
					ptcheck.setPosition(pt[0], pt[1]);
					return (1);
				}
			}
		}
	}
	return (0);
}

void	Sensor::drawRay( sf::RenderWindow& win, Creature& c, Simulation& sim  )
{
	// std::string	path("./images/sensorRayON.png");
	// std::string	path1("./images/sensorRayOFF.png");
	sf::RectangleShape	r; // Left ray
	sf::RectangleShape	r1; // Middle ray
	sf::RectangleShape	r2; // Right ray

	for (unsigned int i = 0; i < _rayCount; i++){

		switch(i){
			case 0:
				this->_raySprite[i].setRotation(c.getRotation() - _rayAngle);
				_state[i] = findIntersection(win, &r, c.getRotation() + _rayAngle, c,  sim.getFood());
				_state[i] ? r.setFillColor( sf::Color::Red ) : r.setFillColor( sf::Color::White );
				break ;
			case 1:
				this->_raySprite[i].setRotation(c.getRotation());
				_state[i] = findIntersection(win, &r1, c.getRotation(), c, sim.getFood());
				_state[i] ? r1.setFillColor( sf::Color::Red ) : r1.setFillColor( sf::Color::White );
				break ;
			case 2:
				this->_raySprite[i].setRotation(c.getRotation() + _rayAngle);
				_state[i] = findIntersection(win, &r2, c.getRotation() - _rayAngle, c, sim.getFood());
				_state[i] ? r2.setFillColor( sf::Color::Red ) : r2.setFillColor( sf::Color::White );
				break ;
			default:
				break ;
		}
		win.draw(r);
		win.draw(r1);
		win.draw(r2);
		win.draw(ptcheck);
	}
	return ;
}
