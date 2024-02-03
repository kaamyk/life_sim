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

#include "../includes/Population.hpp"
#include "../includes/Food.hpp"

#include "../s_data.hpp"

int	main( void )	
{
    srand(time(NULL));
	sf::RenderWindow	win(sf::VideoMode(s_data.windowLength, s_data.windowHeight), "Life Simulation");

	Food	food;
	Population	population;

	win.setFramerateLimit(30);
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;

		while(win.pollEvent(event))
			if (event.type == sf::Event::Closed)
				win.close();
		win.clear();

		
		
		win.display();
	}
	return (0);
}
