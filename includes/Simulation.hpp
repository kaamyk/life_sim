#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <array>
# include <SFML/Graphics.hpp>
# include <cmath>

# define WIN_L 600
# define WIN_H 600
# define NBFOOD 20
# define NBCREAT 5

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
		unsigned int const			_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		std::vector<Creature *>		_population;
		std::vector<NeuralNetwork *> _bestBrains;
		unsigned int				_nbCreature;
		std::vector<Food *>			_food;
		unsigned int				_nbFood;
		assetManager				_assets;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();
		static float	lerp( float A, float B, float t){ return (A + ((B - A) * t)); }

		unsigned int	giveIndex( void );
		std::vector<Food *> const&		getFood( void );
		void			foodGetsEaten( std::vector<Food *>::iterator const& i );
		void			loadTextures( void );
		void			drawPopulation( sf::RenderWindow& win );
		void			drawAllFood( sf::RenderWindow& win );
		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		void			createMutatedCreature( NeuralNetwork const& brain );
		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
		size_t			getPopulationSize( void );
};

#endif
