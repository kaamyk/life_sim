#include "../includes/Sensor.hpp"
#include "../includes/Simulation.hpp"
#include <cmath>

Sensor::Sensor( void ): _rayCount(3), _rayLenght(100),
						_rayAngle(30)
{
	for (__uint8_t i = 0; i < _rayCount; i++){
		_state.push_back(0);
	}
	// ptcheck = sf::RectangleShape(sf::Vector2f(5, 5));
	// ptcheck.setFillColor(sf::Color::Green);
	// ptcheck.setOrigin(2.5f, 2.5f);
	return ;
}

Sensor::~Sensor( void ){
	return ;
}

bool	Sensor::findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, std::vector<Particule *>& particules ){
	double	pt[2];

	r->setSize(sf::Vector2f(1, _rayLenght));
	r->setRotation( rayRotation + 180 );
	r->setPosition (c.getPosition().x, c.getPosition().y);

	if (rayRotation < 0)
		rayRotation += 360;
	else if (rayRotation >= 360)
		rayRotation -= 360;
	for (unsigned int i = 0; i < s_data.nbFood; i++){
		if (particules[i]->getPosition().x < c.getPosition().x + _rayLenght && particules[i]->getPosition().x > c.getPosition().x - _rayLenght
			&& particules[i]->getPosition().y < c.getPosition().y + _rayLenght && particules[i]->getPosition().y > c.getPosition().y - _rayLenght)
		{
			pt[0] = c.getPosition().x;
			pt[1] = c.getPosition().y;
			for(unsigned int j = 0; j < _rayLenght; j++){
				pt[0] = pt[0] + sin(rayRotation * (3.14159265359f / 180.0f));
				pt[1] = pt[1] - cos(rayRotation * (3.14159265359f / 180.0f));
				if (particules[i]->checkPositionSe(pt[0], pt[1])){
					return (1);
				}
			}
		}
	}
	return (0);
}

void	Sensor::drawRays( sf::RenderWindow& win ){
	for (__uint8_t i = 0; i < 4; i++){
		win.draw(_rays[i]);
	}
}

void	Sensor::buildRays( Creature& c, std::vector<Particule *>& particules ){
	for (unsigned int i = 0; i < _rayCount; i++){
		this->_raySprite[i].setRotation(c.getRotation() + _rayAngle);
		_state[i] = findIntersection(&_rays[i], c.getRotation() - _rayAngle, c, particules);
		_state[i] ? _rays[i].setFillColor( sf::Color::Red ) : _rays[2].setFillColor( sf::Color::White );
	}
	
	// std::string	path("./images/sensorRayON.png");
	// std::string	path1("./images/sensorRayOFF.png");
	// sf::RectangleShape	r;	// Left ray
	// sf::RectangleShape	r1;	// Middle ray
	// sf::RectangleShape	r2;	// Right ray

	// for (unsigned int i = 0; i < _rayCount; i++){
	// 	switch(i){
	// 		case 0:
	// 			this->_raySprite[i].setRotation(c.getRotation() - _rayAngle);
	// 			_state[i] = findIntersection(win, &_rays[0], c.getRotation() + _rayAngle, c,  particules);
	// 			_state[i] ? _rays[0].setFillColor( sf::Color::Red ) : _rays[0].setFillColor( sf::Color::White );
	// 			break ;
	// 		case 1:
	// 			this->_raySprite[i].setRotation(c.getRotation());
	// 			_state[i] = findIntersection(win, &_rays[1], c.getRotation(), c, particules);
	// 			_state[i] ? _rays[1].setFillColor( sf::Color::Red ) : _rays[1].setFillColor( sf::Color::White );
	// 			break ;
	// 		case 2:
	// 			this->_raySprite[i].setRotation(c.getRotation() + _rayAngle);
	// 			_state[i] = findIntersection(win, &_rays[2], c.getRotation() - _rayAngle, c, particules);
	// 			_state[i] ? _rays[2].setFillColor( sf::Color::Red ) : _rays[2].setFillColor( sf::Color::White );
	// 			break ;
	// 		default:
	// 			break ;
	// 	}
		// win.draw(r);
		// win.draw(r1);
		// win.draw(r2);
		// win.draw(ptcheck);
	// }
}