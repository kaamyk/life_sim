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
    srand(time(NULL));
	Simulation	sim;
	sf::RenderWindow	win(sf::VideoMode(WIN_L, WIN_H), "Life Simulation");

	win.setFramerateLimit(30);
	sim.loadTextures();
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;

		if (sim.getPopulationSize() == 0){
			for (unsigned int i = 0; i < NBCREAT; ++i){
				sim.createNewCreature();
			}
		}
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
