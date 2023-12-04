#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Simulation.hpp"
# include "Food.hpp"

class Simulation;
class Creature;

class	Sensor
{
	private:
		unsigned int***	_rays;
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		const unsigned int	_rayAngle;
		sf::Texture		_rayTexutre;
		sf::Sprite		_raySprite[3];
		bool			_state[3];

	public:
		Sensor( void );
		~Sensor( void );

		unsigned int getRayCount( void ){return (_rayCount);}

		int		lerp(unsigned int A, unsigned int B, unsigned int t);
		bool	findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, Food* food );
		void	drawRay( sf::RenderWindow& win, assetManager& _assets, Creature& c, Simulation& sim );
};

#endif