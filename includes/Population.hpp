#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Creature.hpp"
#include "NeuralNetwork.hpp"
#include "s_data.hpp"

class Population
{
private:
	std::vector<Creature *>		_population;
	std::vector<NeuralNetwork *> _bestBrains;
    
public:
    Population( void );
    ~Population( void );

    bool	checkNbCreature( void );
	void	checkLifeTimes( void );

	void	drawPopulation( sf::RenderWindow& win );
	
    bool	creatureMove( Creature* Cr, __uint8_t i );
	void	createNewCreature( void );

	void	updatePopulation( Food& food );
	void	createMutatedCreature( NeuralNetwork* brain );


};

#endif