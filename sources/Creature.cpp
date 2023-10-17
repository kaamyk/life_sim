#include "../includes/Creature.hpp"

							// _position {Fixed(rand() % win_l), Fixed(rand() % win_h)},
Creature::Creature( int const win_h, int const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {Fixed(win_l / 2), Fixed(win_h - 5)},
							_rotation(0),
							_direction {0, 0},
							_speed(5),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	_sensor = new Sensor();
	return ;
}

Creature::~Creature( void )
{
	delete _sensor;
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_birthTime >= _timeToDie);
}

Fixed	Creature::getCoordinates( bool xy ) const
{
	return (_position[xy]);
}

void	Creature::drawCreature( sf::RenderWindow& win, assetManager& _assets )
{
	const std::string&	path("./images/creature.png");

	this->_creatureSprite.setTexture(_assets.getTexture(path));
	this->_creatureSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	this->_creatureSprite.setPosition(this->_position[0].toFloat() - (50 / 2), this->_position[1].toFloat() - (50 / 2));
	this->_creatureSprite.setRotation(0);
	win.draw( this->_creatureSprite);
	return ;
}

void	Creature::moveUp( void )
{
	if (_position[1] >= _speed)
		_position[1] = _position[1] - Fixed(_speed);
	else
		_position[1] = _position[1] - (_position[1] - Fixed(_speed));

	if (_rotation >= 20 && _rotation <= 180)
		_rotation = _rotation - Fixed(20) ;
	else if (_rotation > 180 && _rotation <= 340)
		_rotation = _rotation + Fixed(20) ;
	else if ((_rotation > 0 && _rotation < 20) || (_rotation > 340 && _rotation < 360))
		_rotation = 0;
	return ;
}

void	Creature::moveDown( void )
{
	if (_position[1] + _speed <= Fixed(WIN_H))
		_position[1] = _position[1] + Fixed(_speed);
	else
		_position[1] = _position[1] + WIN_H;

	if (_rotation >= 110 && _rotation < 360)
		_rotation = _rotation - Fixed(20) ;
	else if (_rotation > 0 && _rotation <= 70)
		_rotation = _rotation + Fixed(20) ;
	else if ((_rotation > 90 && _rotation < 110) || (_rotation > 70 && _rotation < 90))
		_rotation = 0;
	return ;
}

void	Creature::moveLeft( void )
{
	if (_position[0] >= _speed)
		_position[0] =_position[0] - _speed;
	else
		_position[0] = _position[0] - (_position[0] - _speed);
	if (_rotation != 270 && _rotation >= 180 && _rotation < 270)
		_rotation = _rotation + Fixed(20) ;

	if ((_rotation >= 0 && _rotation <= 90) || (_rotation <= 360 && _rotation > 270))
	{
		if (_rotation - 20 < 0)
			_rotation = _rotation + Fixed(360);
		_rotation = _rotation - Fixed(20) ;
	}
	else if (_rotation > 90 && _rotation <= 250)
		_rotation = _rotation + Fixed(20) ;
	else if ((_rotation > 270 && _rotation < 290) || (_rotation < 270 && _rotation > 250))
		_rotation = 270;
	return ;
}

void	Creature::moveRight( void )
{
	if (_position[0] + _speed <= Fixed(WIN_L))
		_position[0] = _position[0] + _speed;
	else
		_position[0] = _position[0] + Fixed(WIN_L);

	if ((_rotation >= 0 && _rotation < 90) || (_rotation <= 360 && _rotation >= 270))
	{
		if (_rotation + 20 > 360)
			_rotation = (_rotation + 20) - 360;
		else
			_rotation = _rotation - Fixed(20) ;
	}
	else if (_rotation > 110 && _rotation <= 270)
		_rotation = _rotation + Fixed(20) ;
	else if ((_rotation > 90 && _rotation < 110) || (_rotation < 90 && _rotation > 70))
		_rotation = 90;
	return ;
}
