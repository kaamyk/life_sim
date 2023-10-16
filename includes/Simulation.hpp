#ifndef	SIM_HPP
#define SIM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Fixed.hpp"
#include "assetManager.hpp"
#include "Creature.hpp"
#include "Food.hpp"

#define	WIN_H 640
#define WIN_L 480
#define	NBFOOD 10

class	Creature;

class	Simulation
{
	private :
		unsigned int const			_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		std::vector<Creature>		_population;
		unsigned int				_nbCreature;
		Food						_food[10];
		unsigned int				_nbFood;
		assetManager				_assets;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();

		unsigned int	giveIndex( void );
		void			loadTextures( void );
		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
		void			drawPopulation( sf::RenderWindow& win );
		void			drawAllFood( sf::RenderWindow& win );
};

#endif
