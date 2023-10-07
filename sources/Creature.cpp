#include "../includes/Creature.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_position {0, 0},
							_targets {{0, 0}, {0, 0}, {0, 0}},
							_rotation(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	return ;
}

							// _position {(int)(rand() % win_l), (int)(rand() % win_h)},
Creature::Creature( size_t const win_h, size_t const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {640, 480},
							_targets {{0, 0}, {0, 0}, {0, 0}},
							_rotation(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	(void)win_h;
	(void)win_l;
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

void	Creature::printTargets( void )
{
	for(unsigned int i = 0; i < 3; ++i)
		std::cout << "targets[" << i << "][0] == " << _targets[i][0] << " | targets[" << i << "][1] == " << _targets[i][1] << std::endl;
	return ;
}

void	Creature::setTargets( Food food[10] )
{
	for (unsigned int i = 0; i < 10; ++i) // Runs trough food
	{
		for (unsigned int j = 0; j < 3; ++j) // Runs trough _targets
		{
			if (pow(food[i].getCoordinates()[0] - _position[0].toInt(), 2) + pow(food[i].getCoordinates()[1] - _position[1].toInt(), 2)
				< pow( _targets[j][0] + _position[0].toInt(), 2) + pow(_targets[j][1] + _position[1].toInt(), 2)
				|| (!_targets[j][0] && !_targets[j][1]))
			{
				std::cout << "In if => j == " << j << std::endl;
				for (unsigned int k = 2; k > 0 && k != j; --k)
				{
					_targets[k][0] = _targets[k - 1][0];
					_targets[k][1] = _targets[k - 1][1];
				}
				_targets[j][0] = food[i].getCoordinates()[0];
				_targets[j][1] = food[i].getCoordinates()[1];
				++j;
			}
		}
	}
	this->printTargets();
	return ;
}

bool	Creature::targetsEmpty( void )
{
	return (_targets[0][0] || _targets[0][1]);
}

bool	Creature::onFstTarget( void )
{
	return (_position[0] == _targets[0][0] && _position[1] == _targets[0][1]);
}

bool	Creature::onSecTarget( void )
{
	return (_position[0] == _targets[1][0] && _position[1] == _targets[1][1]);
}

bool	Creature::onThrTarget( void )
{
	return (_position[0] == _targets[2][0] && _position[1] == _targets[2][1]);
}

void	Creature::moveToTargets( void )
{
	std::cout << ">>> moveToTarget()" << std::endl;
	_position[0] = _position[0] + ((_targets[0][0] - _position[0].toFloat()) * (_speed.toFloat() / 100));
	_position[1] = _position[1] + ((_targets[0][1] - _position[1].toFloat()) * (_speed.toFloat() / 100));
	std::cout << _position[0] << " | " << _position[1] << std::endl;
	// if (_position[0] == _targets[0] && _position[1] == _targets[1])
	// 	eat();
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
	// std::cout << _position[0] << " | " << _position[1] << std::endl;
	return ;
}
