#ifndef	SIM_HPP
# define SIM_HPP

# include <iostream>
# include <vector>
# include <SFML/Graphics.hpp>

# include "Fixed.hpp"
# include "assetManager.hpp"
# include "Sensor.hpp"
# include "Food.hpp"
# include "Creature.hpp"

# define WIN_L 640
# define WIN_H 640
# define NBFOOD 10

class	Creature;
class	Food;

class	Simulation
{
	private :
		unsigned int const			_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		std::vector<Creature>		_population;
		unsigned int				_nbCreature;
		Food						_food[NBFOOD];
		unsigned int				_nbFood;
		assetManager				_assets;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();
		int				lerp(unsigned int A, unsigned int B, unsigned int t);

		unsigned int	giveIndex( void );
		Food*			getFood( void );
		void			loadTextures( void );
		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
		void			drawPopulation( sf::RenderWindow& win );
		void			drawAllFood( sf::RenderWindow& win );
};

#endif
