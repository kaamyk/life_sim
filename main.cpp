/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include <iostream>
#include "Creature.hpp"
#include "Simulation.hpp"

int	main( void )	
{
	Simulation	sim;

	// sim.printTimeToDie();
	sim.createNewCreature();
	while (sim.checkNbCreature() == 1)
		sim.checkLifeTimes();
	return ( 0 );
}
