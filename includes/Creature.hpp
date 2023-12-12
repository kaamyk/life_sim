#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>

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
		Fixed			_gradientDescent;
		Fixed			_position[2];
		Fixed			_rotation;
		Fixed			_speed;
		Fixed			_size;
		Sensor*			_sensor;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		sf::Texture		_creatureTexture;
		sf::Sprite		_creatureSprite;
		void			(Creature::*_moves[4])( void );
		NeuralNetwork*	_brain;

	public :
		Creature( void );
		Creature( int const win_h, int const win_l );
		~Creature( void );

		bool		checkTime( std::chrono::seconds const _timeToDie );
		Fixed		getPosition( bool xy ) const{ return (_position[xy]); }
		Fixed		getRotation( void ) const{ return (_rotation); }
		Sensor*		getSensor( void ) const{ return (_sensor); }
		std::vector<float> const&	getSensorState( void ) const;
		
		void		drawCreature( sf::RenderWindow& win, assetManager& _assets, Simulation& sim );
		void		move( uint8_t r );
		void		moveUp( void );
		void		moveDown( void );
		void		moveLeft( void );
		void		moveRight( void );
		std::vector<float> const&	feedForward( std::vector<float> sensorInputs ) const;
};

#endif
