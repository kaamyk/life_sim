/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../includes/Creature.hpp"
#include "../includes/Simulation.hpp"

int	main( void )	
{
	Simulation	sim;
	sf::RenderWindow	win(sf::VideoMode(640, 480), "Life Simulation");

	win.setFramerateLimit(30);
	sim.createNewCreature();
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;
		while(win.pollEvent(event))
			if (event.type == sf::Event::Closed)
				win.close();
		sim.checkLifeTimes();
		win.clear();
		sim.drawPopulation(win);
		win.display();
	}
	return ( 0 );
}
