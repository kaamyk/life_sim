#include "../includes/Simulation.hpp"
#include "../includes/assetManager.hpp"
#include "../includes/Food.hpp"

Food::Food( void ): _position {(unsigned int)rand() % data.windowLength, (unsigned int)rand() % data.windowHeight}
{
	return ;
}

Food::~Food( void )
{
	return ;
}

unsigned int	Food::getPosition( bool xy ){
	return (_position[xy]);
}

void			Food::setPosition( unsigned int x, unsigned int y ){
	_position[0] = x;
	_position[1] = y;
}

void			Food::drawFood( sf::RenderWindow& win, assetManager& _assets )
{
	std::string	path("./images/foodParticule.png");

	_foodSprite.setOrigin(data.foodSize / 2, data.foodSize / 2);
	_foodSprite.setTexture(_assets.getTexture(path));
	_foodSprite.setTextureRect(sf::IntRect(0, 0, data.foodSize, data.foodSize));
	_foodSprite.setPosition(_position[0], _position[1]);
	_foodSprite.setRotation(0);
	win.draw(_foodSprite);
	return ;
}

unsigned int*	Food::getCoordinates( void ){
	return (_position);
}