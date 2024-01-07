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
	sf::RenderWindow	win(sf::VideoMode(data.windowLength, data.windowHeight), "Life Simulation");

	win.setFramerateLimit(30);
	sim.loadTextures();
	if (sim.getPopulationSize() == 0){
		for (unsigned int i = 0; i < data.nbCreature; ++i){
			sim.createNewCreature();
		}
	}
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;

		while(win.pollEvent(event))
			if (event.type == sf::Event::Closed)
				win.close();
		sim.checkLifeTimes();
		win.clear();
		sim.updatePopulation(win);
		sim.drawAllFood(win);
		win.display();
	}
	return (0);
}
