#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <array>
# include <SFML/Graphics.hpp>

# define WIN_L 900
# define WIN_H 900
# define NBFOOD 10
# define NBCREAT 10

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
		unsigned int				_nbCreature;
		std::vector<Food *>			_food;
		unsigned int				_nbFood;
		assetManager				_assets;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();
		int				lerp(unsigned int A, unsigned int B, unsigned int t);

		unsigned int	giveIndex( void );
		std::vector<Food *> const&		getFood( void );
		void			foodGetsEaten( std::vector<Food *>::iterator const& i );
		void			loadTextures( void );
		void			drawPopulation( sf::RenderWindow& win );
		void			drawAllFood( sf::RenderWindow& win );
		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
};

#endif
