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
		sf::Texture		_rayTexutre;
		sf::Sprite		_raySprite[3];

	public:
		Sensor( void );
		~Sensor( void );

		int		lerp(unsigned int A, unsigned int B, unsigned int t);
		void	drawRay( sf::RenderWindow& win, assetManager& _assets, Creature& c );
};

#endif