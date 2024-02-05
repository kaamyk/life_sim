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

    bool	creatureMove( Creature* Cr, __uint8_t i );
	void	createNewCreature( void );

	void	updatePopulation( sf::RenderWindow& win, Food& food );
    bool	checkNbCreature( void );
	void	checkLifeTimes( void );
	void	createMutatedCreature( NeuralNetwork* brain );
	static float	lerp( float A, float B, float t){ return (A + ((B - A) * t)); }


};

#endif