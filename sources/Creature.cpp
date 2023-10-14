#include "../includes/Creature.hpp"

							// _position {(int)(rand() % win_l), (int)(rand() % win_h)},
Creature::Creature( size_t const win_h, size_t const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {rand() % win_l, rand() % win_h},
							_targets {{0, 0}, {0, 0}, {0, 0}},
							_rotation(0),
							_direction {0, 0},
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
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

void	Creature::drawCreature( sf::RenderWindow& win, assetManager& _assets )
{
	const std::string&	path("./images/creature.png");

	this->_creatureSprite.setTexture(_assets.getTexture(path));
	this->_creatureSprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	this->_creatureSprite.setPosition(this->_position[0].toFloat(), this->_position[1].toFloat());
	this->_creatureSprite.setRotation(0);
	win.draw( this->_creatureSprite);
	return ;
}

void	Creature::move_up( void )
{
	if (_positon[1] >= _speed)
		_position[1] -= _speed;
	else
		_position[1] -= _position[1] - _speed;

	if (_rotation >= 20 && _rotation <= 180)
		_rotation -= 20;
	else if (_rotation > 180 && _rotation <= 340)
		_rotation += 20;
	else if ((_rotation > 0 && _rotation < 20) || (_rotation > 340 && _rotation < 360))
		_rotation = 0;
	return ;
}

void	Creature::move_down( void )
{
	if (_position[1] + _speed <= WIN_H)
		_position[1] += _speed;
	else
		_position[1] += WIN_H;

	if (_rotation >= 110 && _rotation < 360)
		_rotation -= 20;
	else if (_rotation > 0 && _rotation <= 70)
		_rotation += 20;
	else if ((_rotation > 90 && _rotation < 110) || (_rotation > 70 && _rotation < 90))
		_rotation = 0;
	return ;
}

void	Creature::move_left( void )
{
	if (_position[0] >= _speed)
		_position[0] -= _speed;
	else
		_position[0] -= _position[0] - _speed;
	if (_rotation != 270 && _rotation >= 180 && _rotation < 270)
		_rotation += 20;

	if ((_rotation >= 0 && _rotation <= 90) || (_rotation <= 360 && _rotation > 270))
	{
		if (_rotation - 20 < 0)
			_rotation += 360;
		_rotation -= 20;
	}
	else if (_rotation > 90 && _rotation <= 250)
		_rotation += 20;
	else if ((_rotation > 270 && _rotation < 290) || (_rotation < 270 && _rotation > 250))
		_rotation = 270;
	return ;
}

void	Creature::move_right( void )
{
	if (_position[0] + _speed <= WIN_L)
		_position[0] += _speed;
	else
		_position[0] += WIN_L;

	if ((_rotation >= 0 && _rotation < 90) || (_rotation <= 360 && _rotation >= 270))
	{
		if (_rotation + 20 > 360)
			_rotation = (_rotation + 20) - 360;
		else
			_rotation -= 20;
	}
	else if (_rotation > 110 && _rotation <= 270)
		_rotation += 20;
	else if ((_rotation > 90 && _rotation < 110) || (_rotation < 90 && _rotation > 70))
		_rotation = 90;
	return ;
}
