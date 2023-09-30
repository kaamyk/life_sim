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

#include "Creature.hpp"
#include "Simulation.hpp"

int	main( void )	
{
	Simulation	sim;
	sf::RenderWindow	win(sf::VideoMode(640, 480), "Life Simulation");
	// sf::Texture			texture;
	// sf::Sprite		_creatureSprite;

	win.setFramerateLimit(30);
	// texture.loadFromFile("./creature.png", sf::IntRect(0, 0, 640, 480));
	// std::cout << "Apres loadFromFile" << std::endl;
	// _creatureSprite.setTexture(_creatureTexture);
	// _creatureSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	// _creatureSprite.setPosition(100, 25);
	sim.createNewCreature();
	while (win.isOpen() && sim.checkNbCreature())
	{
		sf::Event	event;
		while(win.pollEvent(event))
			if (event.type == sf::Event::Closed)
				win.close();
		sim.checkLifeTimes();
		win.clear();
		// win.draw( _creatureSprite );
		sim.drawPopulation(win);
		win.display();
	}
	return ( 0 );
}
