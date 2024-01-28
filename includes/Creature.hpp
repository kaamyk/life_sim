#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Simulation.hpp"

class Simulation;
class Sensor;
class Food;
class NeuralNetwork;

class	Creature
{
	private :
		unsigned int	_index;
		unsigned int	_fitness;
		float			_gradientDescent;
		float			_speed;
		float			_size;
		Sensor*			_sensor;
		unsigned int 	_nbFoodEaten;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		std::chrono::high_resolution_clock::time_point	_timeLastEat;
		void			(Creature::*_moves[4])( void );
		NeuralNetwork*	_brain;
		std::vector<sf::Vector2f>	_lastPositions;

		sf::RectangleShape	CrSprite;
		std::array<sf::RectangleShape, 4> pt;

	public :
		Creature( void );
		Creature( NeuralNetwork const& brain );
		~Creature( void );

		bool		checkTime( std::chrono::seconds const _timeToDie );
		sf::Vector2f	getPosition( void ) const{ return (CrSprite.getPosition()); }
		float		getRotation( void ) const{ return (CrSprite.getRotation()); }
		Sensor*		getSensor( void ) const{ return (_sensor); }
		NeuralNetwork&	getBrain( void ){ return (*_brain); }
		std::vector<float> const&	getSensorState( void ) const;
		
		void		drawCheckPoints( sf::RenderWindow& win );
		void		drawCreature( sf::RenderWindow& win, Simulation& sim );

		bool		checkLastPositions( void );
		void		updatePosition( void );

		void		move( uint8_t r );
		void		moveUp( void );
		void		moveDown( void );
		void		moveLeft( void );
		void		moveRight( void );

		std::vector<float> const&	feedForward( std::vector<float> sensorInputs ) const;
		void			giveBirth( NeuralNetwork const& brain, std::vector<Creature *>& _population );
		void			eat( sf::RenderWindow& win, std::vector<Food *>& _food, std::vector<Creature *>& _population );

		void			buildCheckPoints( void );
};

#endif
