#include "../includes/Sensor.hpp"
#include "../includes/Simulation.hpp"
#include <cmath>

Sensor::Sensor( void ): _rayCount(3), _rayLenght(100),
						_rayAngle(30)
{
	_rays = new unsigned int**[_rayCount];
	for(unsigned int i = 0; i < _rayCount; ++i)
	{
		_rays[i] = new unsigned int*[2];
		_rays[i][0] = new unsigned int[2];
		_rays[i][1] = new unsigned int[2];
		_state.push_back(0);
	}
	return ;
}

Sensor::~Sensor( void )
{
	for(unsigned int i = 0; i < _rayCount; ++i)
	{
		delete _rays[i][0];
		delete _rays[i][1];
		delete _rays[i];
	}
	delete [] _rays;
	return ;
}

int		Sensor::lerp(unsigned int A, unsigned int B, unsigned int t)
{
	return (A + ((B - A) * t));
}

bool	Sensor::findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, Food* food )
{
	double	pt[2];

	r->setSize(sf::Vector2f(1, _rayLenght));
	r->setRotation( rayRotation + 180 );
	r->setPosition (c.getPosition(0).toInt(), c.getPosition(1).toInt());

	if (rayRotation < 0)
		rayRotation += 360;
	else if (rayRotation >= 360)
		rayRotation -= 360;
	for (unsigned int i = 0; i < NBFOOD; ++i)
	{
		if (food[i].getPosition(0) < c.getPosition(0).toInt() + _rayLenght && food[i].getPosition(0) > c.getPosition(0).toInt() - _rayLenght
			&& food[i].getPosition(1) < c.getPosition(1).toInt() + _rayLenght && food[i].getPosition(1) > c.getPosition(1).toInt() - _rayLenght)
		{
			pt[0] = c.getPosition(0).toFloat();
			pt[1] = c.getPosition(1).toFloat();
			for(unsigned int j = 0; j < _rayLenght; ++j)
			{
				pt[0] = pt[0] + sin(rayRotation * (3.14159265359f / 180));
				pt[1] = pt[1] - cos(rayRotation * (3.14159265359f / 180));
				if (food[i].checkPosition(pt[0], pt[1]))
					return (1);
			}
		}
	}
	return (0);
}

void	Sensor::drawRay( sf::RenderWindow& win, assetManager& _assets, Creature& c, Simulation& sim  )
{
	std::string	path("./images/sensorRayON.png");
	std::string	path1("./images/sensorRayOFF.png");
	sf::RectangleShape	r; // Left ray
	sf::RectangleShape	r1; // Middle ray
	sf::RectangleShape	r2; // Right ray

	for (unsigned int i = 0; i < _rayCount; ++i){

		switch(i){
			case 0:
				this->_raySprite[i].setRotation(c.getRotation().toInt() - _rayAngle);
				_state[i] = findIntersection(&r, c.getRotation().toInt() + _rayAngle, c, sim.getFood());
				_state[i] ? r.setFillColor( sf::Color::Red ) : r.setFillColor( sf::Color::White );
				break ;
			case 1:
				this->_raySprite[i].setRotation(c.getRotation().toInt());
				_state[i] = findIntersection(&r1, c.getRotation().toInt(), c, sim.getFood());
				_state[i] ? r1.setFillColor( sf::Color::Red ) : r1.setFillColor( sf::Color::White );
				break ;
			case 2:
				this->_raySprite[i].setRotation(c.getRotation().toInt() + _rayAngle);
				_state[i] = findIntersection(&r2, c.getRotation().toInt() - _rayAngle, c, sim.getFood());
				_state[i] ? r2.setFillColor( sf::Color::Red ) : r2.setFillColor( sf::Color::White );
				break ;
			default:
				break ;
		}
		win.draw(r);
		win.draw(r1);
		win.draw(r2);
		(void)_assets;
	}
	return ;
}
