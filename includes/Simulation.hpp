#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <array>
# include <SFML/Graphics.hpp>
# include <cmath>

// # define WIN_L 1920
// # define WIN_H 1080
// # define NBFOOD 30
// # define NBCREAT 5

struct{
	const unsigned int	windowLength = 1920;
	const unsigned int	windowHeight = 1080;
	const unsigned int	creatureSize = 25;
	const unsigned int	foodSize = 12;
	const unsigned int	nbCreature = 5;
	const unsigned int	nbFood = 30;
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
		// unsigned int const			_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		std::vector<Creature *>		_population;
		std::vector<NeuralNetwork *> _bestBrains;
		// unsigned int				_nbCreature;
		std::vector<Food *>			_food;
		unsigned int				_nbFood;
		assetManager				_assets;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();
		void			printData( void );
		static float	lerp( float A, float B, float t){ return (A + ((B - A) * t)); }

		unsigned int	giveIndex( void );
		std::vector<Food *> const&		getFood( void );
		size_t			getPopulationSize( void );

		bool			checkNbCreature( void );
		void			checkLifeTimes( void );

		void			loadTextures( void );
		void			drawPopulation( sf::RenderWindow& win );
		void			drawAllFood( sf::RenderWindow& win );

		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		void			createMutatedCreature( NeuralNetwork const& brain );

		void			foodGetsEaten( std::vector<Food *>::iterator const& i );
};

#endif
