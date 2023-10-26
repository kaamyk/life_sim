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

bool	Sensor::findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, Food* food )
{
	double	pt[2];

	r->setSize(sf::Vector2f(10, _rayLenght));
	r->setOrigin(5, 0);
	r->setRotation( rayRotation );
	r->setFillColor( sf::Color(255, 255, 255, 0));
	r->setPosition (c.getPosition(0).toInt(), c.getPosition(1).toInt());

	if (rayRotation < 0)
		rayRotation += 360;
	for (unsigned int i = 0; i < NBFOOD; ++i)
	{
		if (food[i].getPosition(0) < c.getPosition(0).toInt() + _rayLenght && food[i].getPosition(0) > c.getPosition(0).toInt() - _rayLenght
			&& food[i].getPosition(1) < c.getPosition(1).toInt() + _rayLenght && food[i].getPosition(1) > c.getPosition(1).toInt() - _rayLenght)
		{
			// std::cout << "Creature rotation == " << c.getRotation() << std::endl;
			// std::cout << "rayRotation == " << rayRotation << std::endl;
			pt[0] = c.getPosition(0).toInt();
			pt[1] = c.getPosition(1).toInt();
			// std::cout << "Origin = { x == " << pt[0] << " ; y == " << pt[1] << "}"  << std::endl; 
			// std::cout << "End    = { x == " << pt[0] + (sin(rayRotation) * _rayLenght)
			// << " ; y == " << pt[1] + (cos(rayRotation) * _rayLenght) << "}"  << std::endl; 
			for(unsigned int j = 0; j < _rayLenght; ++j)
			{
				pt[0] = pt[0] + sin(rayRotation);
				pt[1] = pt[1] + cos(rayRotation);
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
	sf::RectangleShape	r;
	sf::RectangleShape	r1;
	sf::RectangleShape	r2;

	for (unsigned int i = 0; i < _rayCount; ++i){
		// std::cout << "ray[" << i << "]: ";
		int rayAngle = this->lerp(_raySpread.toInt() / 2, -(_raySpread.toInt() / 2), i / (_rayCount - 1));
		_rays[i][0][0] = c.getPosition(0).toInt();
		_rays[i][0][1] = c.getPosition(1).toInt();
		_rays[i][1][0] = c.getPosition(0).toInt() + sin(rayAngle) * _rayLenght;
		_rays[i][1][1] = c.getPosition(1).toInt() + cos(rayAngle) * _rayLenght;
		// std::cout << "ray [" << i << "] start = {x == "  << _rays[i][0][0] << "; y == " << _rays[i][0][1] << "}" << std::endl;
		// std::cout << "ray [" << i << "] end   = {x == "  << _rays[i][1][0] << "; y == " << _rays[i][1][1] << "}" << std::endl;

		this->_raySprite[i].setOrigin(2.5f, 80);
		switch(i){
			case 0:
				this->_raySprite[i].setRotation(c.getRotation().toInt() - 15);
				_state[i] = findIntersection(&r, c.getRotation().toInt() - 10, c, sim.getFood());
				break ;
			case 1:
				this->_raySprite[i].setRotation(c.getRotation().toInt());
				_state[i] = findIntersection(&r1, c.getRotation().toInt(), c, sim.getFood());
				break ;
			case 2:
				this->_raySprite[i].setRotation(c.getRotation().toInt() + 15);
				_state[i] = findIntersection(&r2, c.getRotation().toInt() + 10, c, sim.getFood());
				break ;
			default:
				break ;
			win.draw(r);
			win.draw(r1);
			win.draw(r2);
		}
		(void)_assets;
		// if (_state[i])
		// 	this->_raySprite[i].setTexture(_assets.getTexture(path));
		// else
		// 	this->_raySprite[i].setTexture(_assets.getTexture(path1));
		// this->_raySprite[i].setTextureRect(sf::IntRect(0, 0, 5, 80));
		// this->_raySprite[i].setPosition(this->_rays[i][0][0] - (50 / 2), this->_rays[i][0][1] - (50 / 2));
		win.draw( this->_raySprite[i]);
		// std::cout << std::endl;
	}
	return ;
}
