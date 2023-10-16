#include "../includes/Sensor.hpp"
#include <cmath>

void	Sensor( void ): 	_rayCount(3), _rayLenght(50 + 20),
								_raySpread(Fixed(3.14159265359) / 4)
{
	_rays = new unsigned int[_rayCount];
	for(unsigned int i = 0; i < 4; ++i)
	{
		_rays[i] = new unsigned int[2];
		_rays[i][0] = new unsigned int[2];
		_rays[i][1] = new unsigned int[2];
	}
	return ;
}

void	~Sensor( void )
{
	
	return ;
}

void	update( Crature c )
{
	for (unsigned int i = 0; i < _rayCount; ++i)
	{
		unsigned int rayAngle = Simulation::lerp(_raySpread / 2, -(_raySpread / 2), i / (_rayCount - 1));
		unsigned int start[2] = {c.getPosition[0], c.getPosition[1]};
	}
}
