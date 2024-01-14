#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <array>
# include <SFML/Graphics.hpp>
# include <cmath>
#include <chrono>

struct{
	const unsigned int	windowLength = 1920;
	const unsigned int	windowHeight = 1080;
	const unsigned int	creatureSize = 20;
	const unsigned int	foodSize = 15;
	const unsigned int	nbCreature = 20;
	const unsigned int	nbFood = 60;
	const std::chrono::seconds	timeToDie = std::chrono::seconds(40);
} data;

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
		std::vector<Creature *>		_population;
		std::vector<NeuralNetwork *> _bestBrains;
		std::vector<Food *>			_food;
		unsigned int				_nbFood;
		assetManager				_assets;


		void			printTimeToDie();
		void			printData( void );

		std::vector<Creature *>&	getPopulation( void );
		size_t			getPopulationSize( void );


		void			creatureMove( Creature* Cr );
		void			createNewCreature( void );

	public :
		Simulation( void );
		~Simulation( void );

		std::vector<Food *> const&	getFood( void );
		
		static float	lerp( float A, float B, float t){ return (A + ((B - A) * t)); }

		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
		void			updatePopulation( sf::RenderWindow& win );
		void			loadTextures( void );
		void			drawAllFood( sf::RenderWindow& win );
};

#endif
