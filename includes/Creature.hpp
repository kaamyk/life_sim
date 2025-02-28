#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Simulation.hpp"

class Sensor;
class Food;
class NeuralNetwork;

class	Creature
{
	private :
		float			_gradientDescent;
		float			_speed;
		float			_size;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		std::chrono::high_resolution_clock::time_point	_timeLastEat;
		void			(Creature::*_moves[4])( void );
		Sensor*			_sensor;
		NeuralNetwork*	_brain;
		std::vector<sf::Vector2f>	_lastPositions;

		sf::RectangleShape	crSprite;
		std::array<sf::RectangleShape, 4> crVtx;

		std::array<sf::Vector2f, 4> bspChck;

	public :
		Creature( void );
		Creature( NeuralNetwork* brain );
		~Creature( void );

		bool			checkTime( std::chrono::seconds const _timeToDie );
		sf::Vector2f	getPosition( void ) const{ return (crSprite.getPosition()); }
		float			getRotation( void ) const{ return (crSprite.getRotation()); }
		Sensor*			getSensor( void ) const{ return (_sensor); }
		NeuralNetwork&	getBrain( void ){ return (*_brain); }
		std::vector<float> const&	getSensorState( void ) const;
		
		void		drawCheckPoints( sf::RenderWindow& win );
		void		drawCreature( sf::RenderWindow& win );

		bool		checkLastPositions( void );
		void		updatePosition( void );
		void		updateSensors( Food& food );

		void		move( uint8_t r );
		void		moveUp( void );
		void		moveDown( void );
		void		moveLeft( void );
		void		moveRight( void );

		std::vector<float> const&	feedForward( std::vector<float> sensorInputs ) const;
		Creature*		giveBirth( NeuralNetwork* brain );
		void			getVtxPos( std::array<sf::Vector2f, 4> *res );
		Creature*		eat( Food& food );

		void			updateCheckPoints( void );
};

#endif