#include "../includes/Sensor.hpp"
#include "../includes/Simulation.hpp"
#include <cmath>

Sensor::Sensor( void ): _rayCount(3), _rayLenght(50),
						_raySpread(Fixed(3.14159265359f) / 4)
{
	_rays = new unsigned int**[_rayCount];
	for(unsigned int i = 0; i < _rayCount; ++i)
	{
		_rays[i] = new unsigned int*[2];
		_rays[i][0] = new unsigned int[2];
		_rays[i][1] = new unsigned int[2];
		_state[i] = 0;
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

void	Sensor::findIntersection( Creature& c, Food* food )
{
	for (unsigned int i = 0; i < NBFOOD; ++i)
	{
		for (unsigned int j = 0; j < _rayCount; ++j)
		{
			if (food[i]->getPosition[0] < c.getPosition[0] + _rayLenght && food[i]->getPosition[0] > c.getPosition[0] + _rayLenght
				&& food[i]->getPosition[1] < c.getPosition[1] + _rayLenght && food[i]->getPosition[1] > c.getPosition[1] + _rayLenght)
			{
				_state[1] = 1;
			}
		}
	}
}

void	Sensor::drawRay( sf::RenderWindow& win, assetManager& _assets, Creature& c )
{
	findIntersection(c, sim.getFooo());
	if (_state[1])
		const std::string&	path("./images/sensorRayON.png");
	else
		const std::string&	path("./images/sensorRayOFF.png");

	for (unsigned int i = 0; i < 3; ++i){
		int rayAngle = this->lerp(_raySpread.toInt() / 2, -(_raySpread.toInt() / 2), i / (_rayCount - 1));
		_rays[i][0][0] = c.getCoordinates(0).toInt();
		_rays[i][0][1] =  c.getCoordinates(1).toInt();
		_rays[i][1][0] = c.getCoordinates(0).toInt() - sin(rayAngle) * _rayLenght;
		_rays[i][1][1] = c.getCoordinates(1).toInt() - cos(rayAngle) * _rayLenght;

		this->_raySprite[i].setOrigin(2.5f, 80);
		this->_raySprite[i].setTexture(_assets.getTexture(path));
		this->_raySprite[i].setTextureRect(sf::IntRect(0, 0, 5, 80));
		this->_raySprite[i].setPosition(this->_rays[i][0][0] - (50 / 2), this->_rays[i][0][1] - (50 / 2));
		switch(i){
			case 0:
				this->_raySprite[i].setRotation(c.getRotation().toInt() - 10);
				break ;
			case 1:
				this->_raySprite[i].setRotation(c.getRotation().toInt());
				break ;
			case 2:
				this->_raySprite[i].setRotation(c.getRotation().toInt() + 10);
				break ;
			default:
				break ;
		}
		win.draw( this->_raySprite[i]);
	}
	return ;
}
