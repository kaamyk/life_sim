#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Simulation.hpp"

class Creature;

class	Sensor
{
	private:
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		Fixed			_raySpread;
		unsigned int***	_rays;
		sf::Vertex		_raySprite[2];

	public:
		Sensor( void );
		~Sensor( void );

		void	update( Creature c );
		void	drawRay( sf::RenderWindow& win );
};

#endif