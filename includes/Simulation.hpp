#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <array>
# include <SFML/Graphics.hpp>
# include <cmath>
#include <chrono>



// # include "float.hpp"
# include "assetManager.hpp"
# include "Creature.hpp"
# include "Sensor.hpp"
# include "Food.hpp"
# include "NeuralNetwork.hpp"
# include "Level.hpp"

class	Level;
class	Creature;
class	Food;

class	Simulation
{
	private :

	public :
		Simulation( void );
		~Simulation( void );
};

#endif
