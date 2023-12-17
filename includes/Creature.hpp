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
		float			_gradientDescent;
		float			_position[2];
		float			_rotation;
		float			_speed;
		float			_size;
		Sensor*			_sensor;
		unsigned int 	_nbFoodEaten;
		std::chrono::high_resolution_clock::time_point	_birthTime;
		std::chrono::high_resolution_clock::time_point	_timeLastEat;
		sf::Texture		_creatureTexture;
		sf::Sprite		_creatureSprite;
		void			(Creature::*_moves[4])( void );
		NeuralNetwork*	_brain;

	public :
		Creature( void );
		Creature( int const win_h, int const win_l );
		Creature( int const win_h, int const win_l, NeuralNetwork const& brain );
		~Creature( void );

		bool		checkTime( std::chrono::seconds const _timeToDie );
		float		getPosition( bool xy ) const{ return (_position[xy]); }
		float		getRotation( void ) const{ return (_rotation); }
		Sensor*		getSensor( void ) const{ return (_sensor); }
		NeuralNetwork&	getBrain( void ){ return (*_brain); }
		std::vector<float> const&	getSensorState( void ) const;
		
		void		drawCreature( sf::RenderWindow& win, assetManager& _assets, Simulation& sim );
		void		move( uint8_t r );
		void		moveUp( void );
		void		moveDown( void );
		void		moveLeft( void );
		void		moveRight( void );
		std::vector<float> const&	feedForward( std::vector<float> sensorInputs ) const;
		void	eat( std::vector<Food *> const& _food, std::vector<Food *>::iterator& it );
};

#endif
