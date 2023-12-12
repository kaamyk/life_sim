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

#include "../includes/Simulation.hpp"
#include "../includes/Creature.hpp"

int	main( void )	
{
	Simulation	sim;
    srand(time(NULL));
	sf::RenderWindow	win(sf::VideoMode(WIN_L, WIN_H), "Life Simulation");

	win.setFramerateLimit(30);
	sim.loadTextures();
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;
		while(win.pollEvent(event))
			if (event.type == sf::Event::Closed)
				win.close();
		sim.checkLifeTimes();
		win.clear();
		sim.drawPopulation(win);
		sim.drawAllFood(win);
		win.display();
	}
	// sf::Event	event;
	// while(win.pollEvent(event))
	// 	if (event.type == sf::Event::Closed)
	// 		win.close();
	// sim.checkLifeTimes();
	// win.clear();
	// sim.drawPopulation(win);
	// sim.drawAllFood(win);
	// win.display();
	return ( 0 );
}
