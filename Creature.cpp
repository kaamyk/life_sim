#include <iostream>

#include "Creature.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	std::cout << "Constructor Creature" << std::endl;
	if (this->_creatureTexture.loadFromFile("creature.png") == 0)
	{
		std::cerr << "\t>>> Image loading failed <<<" << std::endl;
	}
	this->_creatureSprite.setTexture(this->_creatureTexture);
	return ;
}

Creature::~Creature( void )
{
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_birthTime >= _timeToDie);
}

void	Creature::drawCreature( sf::RenderWindow& win )
{
	win.draw( this->_creatureSprite);
	return ;
}
