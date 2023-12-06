#include "../includes/Simulation.hpp"

Creature::Creature( int const win_h, int const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {Fixed(win_l / 2), Fixed(win_h / 2)},
							_rotation(0),
							_speed(5),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	_sensor = new Sensor();
	std::vector<unsigned int>	neuronCount;
	neuronCount.push_back(_sensor->getRayCount());
	neuronCount.push_back(6);
	neuronCount.push_back(4);
	_brain = new NeuralNetwork(neuronCount);
	return ;
}

Creature::~Creature( void )
{
	delete _sensor;
	delete _brain;
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_birthTime >= _timeToDie);
}

Fixed	Creature::getPosition( bool xy ) const
{
	return (_position[xy]);
}

Fixed	Creature::getRotation( void ) const
{
	return (_rotation);
}

Sensor*	Creature::getSensor( void ) const
{
	return (_sensor);
}

void	Creature::drawCreature( sf::RenderWindow& win, assetManager& _assets, Simulation& sim )
{
	const std::string&	path("./images/creature.png");

	_sensor->drawRay(win, _assets, *this, sim);
	this->_creatureSprite.setOrigin(50 / 2, 50 / 2);
	this->_creatureSprite.setTexture(_assets.getTexture(path));
	this->_creatureSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	this->_creatureSprite.setPosition(this->_position[0].toFloat(), this->_position[1].toFloat());
	this->_creatureSprite.setRotation(_rotation.toFloat());
	win.draw( this->_creatureSprite );
	return ;
}

void	Creature::moveUp( void )
{
	if (_position[1] >= Fixed(_speed))
		_position[1] = _position[1] - Fixed(_speed);
	else
		_position[1] = _position[1] + WIN_H;

	if (_rotation.toInt() >= 10 && _rotation.toInt() <= 180){
		_rotation = _rotation - Fixed(10) ;
	}
	else if (_rotation.toInt() > 180 && _rotation.toInt() <= 350){
		_rotation = _rotation + Fixed(10) ;
	}
	else if ((_rotation.toInt() > 0 && _rotation.toInt() < 10) || (_rotation.toInt() > 350 && _rotation.toInt() < 360)){
		_rotation = 0;
	}
	return ;
}

void	Creature::moveDown( void )
{
	if (_position[1] + Fixed(_speed) <= Fixed(WIN_H))
		_position[1] = _position[1] + Fixed(_speed);
	else
		_position[1] = _position[1] - WIN_H;

	if (_rotation.toInt() == 360)
		_rotation = 0;
	if (_rotation.toInt() >= 190 && _rotation.toInt() < 360){
		_rotation = _rotation - Fixed(10);
	}
	else if ((_rotation.toInt() >= 0) && _rotation.toInt() <= 170){
		_rotation = _rotation + Fixed(10);
	}
	else if (_rotation.toInt() > 170 && _rotation.toInt() < 100){
		_rotation = Fixed(180);
	}
	return ;
}

void	Creature::moveLeft( void )
{
	if (_position[0] >= Fixed(_speed))
		_position[0] =_position[0] - Fixed(_speed);
	else
		_position[0] = _position[0] + Fixed(WIN_L);

	if ((_rotation.toInt() >= 0 && _rotation.toInt() <= 90) || (_rotation.toInt() <= 360 && _rotation.toInt() > 280)){
		if (_rotation.toInt() - 10 < 0){
			_rotation = _rotation + Fixed(360);
		}
		_rotation = _rotation - Fixed(10) ;
	}
	else if (_rotation.toInt() > 90 && _rotation.toInt() <= 260){
		_rotation = _rotation + Fixed(10) ;
	}
	else if (_rotation.toInt() >= 260 && _rotation.toInt() <= 280){
		_rotation = Fixed(270);
	}
	return ;
}

void	Creature::moveRight( void )
{
	if (_position[0] + Fixed(_speed) <= Fixed(WIN_L))
		_position[0] = _position[0] + Fixed(_speed);
	else
		_position[0] = _position[0] - Fixed(WIN_L);

	if ((_rotation.toInt() >= 0 && _rotation.toInt() < 80)
		|| (_rotation.toInt() >= 280 && _rotation.toInt() <= 360))
	{
		if (_rotation.toInt() + 10 > 360){
			_rotation = Fixed(_rotation.toInt() + 10) - 360;
		}
		else{
			_rotation = _rotation + Fixed(10) ;
		}
	}
	else if (_rotation.toInt() > 100 && _rotation.toInt() < 280){
		_rotation = _rotation - Fixed(10) ;
	}
	else if (_rotation.toInt() >= 80 && _rotation.toInt() <= 100){
		_rotation = Fixed(90);
	}
	return ;
}

std::vector<float> const&	Creature::feedForward( std::vector<float> sensorInputs ) const
{
	return (_brain->feedForward(sensorInputs));
	
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		// 	i->moveUp();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		// 	i->moveDown();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		// 	i->moveRight();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		// 	i->moveLeft();

}


