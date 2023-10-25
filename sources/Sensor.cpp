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

bool	Sensor::findIntersection( unsigned int** ray, int rayRotation, Creature& c, Food* food )
{
	unsigned int	pt[2];

	for (unsigned int i = 0; i < NBFOOD; ++i)
	{
		if (food[i].getPosition(0) < c.getPosition(0).toInt() + _rayLenght && food[i].getPosition(0) > c.getPosition(0).toInt() - _rayLenght
			&& food[i].getPosition(1) < c.getPosition(1).toInt() + _rayLenght && food[i].getPosition(1) > c.getPosition(1).toInt() - _rayLenght)
		{
			pt[0] = ray[0][0];
			pt[1] = ray[0][1];
			for(unsigned int j = 0; j < _rayLenght; ++j)
			{
				pt[0] = pt[0] - sin(rayRotation);
				pt[1] = pt[1] - cos(rayRotation);
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

	for (unsigned int i = 0; i < _rayCount; ++i){
		int rayAngle = this->lerp(_raySpread.toInt() / 2, -(_raySpread.toInt() / 2), i / (_rayCount - 1));
		_rays[i][0][0] = c.getPosition(0).toInt();
		_rays[i][0][1] = c.getPosition(1).toInt();
		_rays[i][1][0] = c.getPosition(0).toInt() - sin(rayAngle) * _rayLenght;
		_rays[i][1][1] = c.getPosition(1).toInt() - cos(rayAngle) * _rayLenght;

		this->_raySprite[i].setOrigin(2.5f, 80);
		switch(i){
			case 0:
				this->_raySprite[i].setRotation(c.getRotation().toInt() - 10);
				_state[i] = findIntersection(_rays[i], c.getRotation().toInt() - 10, c, sim.getFood());
				break ;
			case 1:
				this->_raySprite[i].setRotation(c.getRotation().toInt());
				_state[i] = findIntersection(_rays[i], c.getRotation().toInt(), c, sim.getFood());
				break ;
			case 2:
				this->_raySprite[i].setRotation(c.getRotation().toInt() + 10);
				_state[i] = findIntersection(_rays[i], c.getRotation().toInt() + 10, c, sim.getFood());
				break ;
			default:
				break ;
		}
		if (_state[i])
			this->_raySprite[i].setTexture(_assets.getTexture(path));
		else
			this->_raySprite[i].setTexture(_assets.getTexture(path1));
		this->_raySprite[i].setTextureRect(sf::IntRect(0, 0, 5, 80));
		this->_raySprite[i].setPosition(this->_rays[i][0][0] - (50 / 2), this->_rays[i][0][1] - (50 / 2));
		win.draw( this->_raySprite[i]);
	}
	return ;
}
