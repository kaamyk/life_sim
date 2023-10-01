#include "Creature.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_position {0, 0},
							_rotation(0),
							_speed(rand() % 100),
							_size(rand() % 100),
							_birthTime(std::chrono::high_resolution_clock::now())
{
	return ;
}

Creature::Creature( size_t const win_h, size_t const win_l ): _fitness(0),
							_gradientDescent(0),
							_position {rand() % win_l, rand() % win_h},
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
	this->_creatureSprite.setPosition(this->_position[0], this->_position[1]);
	this->_creatureSprite.setRotation(0);
	win.draw( this->_creatureSprite);
	return ;
}

void	Creature::move( size_t win_l, size_t win_h )
{
	bool	n;

	std::cout << "_speed = " << this->_speed << std::endl;
	n = rand() % 2;
 	if ((int)(this->_position[0] + ((-1 * n) * (this->_speed / 100))) < 0)
		this->_position[0] = win_l;
	else if (this->_position[0] + ((-1 * n) * (this->_speed / 100)) >= win_l)
		this->_position[0] = 0;
	else
		this->_position[0] += (-1 * n) * (this->_speed / 100);

	n = rand() % 2;
	if ((int)(this->_position[1] + ((-1 * n) * (this->_speed / 100))) < 0)
		this->_position[1] = win_h;
	else if (this->_position[1] + ((-1 * n) * (this->_speed / 100)) >= win_h)
		this->_position[1] = 0;
	else
		this->_position[1] += (-1 * n) * (this->_speed / 100);
	return ;
}
