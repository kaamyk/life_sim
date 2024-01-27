#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Simulation.hpp"
# include "Food.hpp"

class Simulation;
class Creature;

class	Sensor
{
	private:
		// unsigned int***	_rays;
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		const unsigned int	_rayAngle;
		sf::Texture		_rayTexutre;
		sf::Sprite		_raySprite[3];
		std::vector<float>	_state;

		sf::RectangleShape ptcheck;

	public:
		Sensor( void );
		~Sensor( void );

		unsigned int& getRayCount( void ){return (_rayCount);}
		std::vector<float> const&	getState( void ) const {
			// // std::cout<< ">>> getState()" << std::endl;
			return (_state);
		}

		// int		lerp(unsigned int A, unsigned int B, unsigned int t){ return (A + ((B - A) * t)); }
		bool	findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, std::vector<Food *> const& food );
		void	drawRay( sf::RenderWindow& win, Creature& c, Simulation& sim );
};

#endif