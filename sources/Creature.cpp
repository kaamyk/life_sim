#include "../includes/Creature.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_position {0, 0},
							_target {0, 0},
							_rotation(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	return ;
}

Creature::Creature( size_t const win_h, size_t const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {(int)(rand() % win_l), (int)(rand() % win_h)},
							_target {0, 0},
							_rotation(0),
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

void	Creature::setTarget( unsigned int x, unsigned int y )
{
	this->_target[0] = x;
	this->_target[1] = y;
	return ;
}

bool	Creature::checkTarget( void )
{
	return (_target[0] || _target[1]);
}

void	Creature::moveToTarget( void )
{
	std::cout << ">>> moveTarget()" << std::endl;
	_position[0] = _position[0] + ((_target[0] - _position[0].toFloat()) * (_speed.toFloat() / 100));
	_position[1] = _position[1] + ((_target[1] - _position[1].toFloat()) * (_speed.toFloat() / 100));
}

void	Creature::moveRandom( unsigned int win_l, unsigned int win_h )
{
	bool	n;

	std::cout << ">>> moveRandom()" << std::endl;
	n = rand() % 2;
 	if ((this->_position[0].toFloat() + ((-1 * n) * (this->_speed.toFloat() / 100))) < 0)
		this->_position[0].setRawBits(win_l);
	else if (this->_position[0].toFloat() + ((-1 * n) * (this->_speed.toFloat() / 100)) >= win_l)
		this->_position[0].setRawBits(0);
	else
		this->_position[0] = this->_position[0] + (-1 * n) * (this->_speed.toFloat() / 100);

	n = rand() % 2;
	if ((int)(this->_position[1].toFloat() + ((-1 * n) * (this->_speed.toFloat() / 100))) < 0)
		this->_position[1].setRawBits(win_h);
	else if (this->_position[1].toFloat() + ((-1 * n) * (this->_speed.toFloat() / 100)) >= win_h)
		this->_position[1].setRawBits(0);
	else
		this->_position[1] = this->_position[1] + (-1 * n) * (this->_speed.toFloat() / 100);
	std::cout << _position[0] << " | " << _position[1] << std::endl;
	return ;
}
