#ifndef	SIM_HPP
#define SIM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Fixed.hpp"
#include "Creature.hpp"

class	Simulation
{
	private :
		unsigned int const			_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		std::vector<Creature>		_population;
		unsigned int				_nbCreature;


	public :
		Simulation( void );
		~Simulation( void );

		void			printTimeToDie();

		unsigned int	giveIndex( void );
		void			updateNbCreature( bool a );
		void			createNewCreature( void );
		bool			checkNbCreature( void );
		void			checkLifeTimes( void );
		void			drawPopulation( sf::RenderWindow& win );
};

#endif
