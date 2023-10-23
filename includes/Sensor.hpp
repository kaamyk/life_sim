#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Simulation.hpp"
# include "Food.hpp"

class Simulation;
class Creature;

class	Sensor
{
	private:
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		Fixed			_raySpread;
		unsigned int***	_rays;
		sf::Texture		_rayTexutre;
		sf::Sprite		_raySprite[3];
		bool			_state[3];

	public:
		Sensor( void );
		~Sensor( void );

		int		lerp(unsigned int A, unsigned int B, unsigned int t);
		void	findIntersection( Creature& c, Food* food );
		void	drawRay( sf::RenderWindow& win, assetManager& _assets, Creature& c, Simulation& sim );
};

#endif