#include <iostream>
#include <vector>

#include "Fixed.hpp"

class	Simulation
{
	private :
		size_t const				_nbMaxCreature;
		std::chrono::seconds const	_timeToDie;
		vector<Creature>			_population;
		size_t						_nbCreature;


	public :
		Simulation( void );
		~Simulation( void );

		size_t	giveIndex( void );
		void	updateNbCreature( bool a );
		void	createNewCreature( void );
		bool	checkNbCreature( void );
		void	checkLifeTimes( void );
}
