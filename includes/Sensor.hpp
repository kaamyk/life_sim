#ifndef SENSOR_HPP
# define SENSOR_HPP

# include "Simulation.hpp"

class	Sensor:
{
	private:
		unsigned int	_rayCount;
		unsigned int	_rayLenght;
		unsigned int	_raySpread;
		unsigned int	***_rays;
	public:
		Sensor( void );

};

#endif