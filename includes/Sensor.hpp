#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Food.hpp"
#include "s_data.hpp"

class Creature;

class	Sensor
{
	private:
		// unsigned int***	_rays;
		std::array<sf::RectangleShape, 3>	_rays;
		std::array<sf::RectangleShape, 3>	_raySprite;
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		const unsigned int	_rayAngle;
		// sf::Texture		_rayTexutre;
		std::vector<float>	_state;

		// sf::RectangleShape _ptcheck;

	public:
		Sensor( void );
		~Sensor( void );

		unsigned int& getRayCount( void ){return (_rayCount);}
		std::vector<float> const&	getState( void ) const {
			// // std::cout<< ">>> getState()" << std::endl;
			return (_state);
		}

		// int		lerp(unsigned int A, unsigned int B, unsigned int t){ return (A + ((B - A) * t)); }
		bool	findIntersection( sf::RectangleShape* r, int rayRotation, Creature& c, std::vector<Particule *>& particules );
		void	buildRays( Creature& c, std::vector<Particule *>& particules );
		void	drawRays( sf::RenderWindow& win );
};

#endif