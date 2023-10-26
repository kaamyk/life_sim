#include "../includes/Simulation.hpp"
#include "../includes/assetManager.hpp"
#include "../includes/Food.hpp"

Food::Food( void ): _position {(unsigned int)rand() % WIN_H, (unsigned int)rand() % WIN_L}
{
	return ;
}

Food::~Food( void )
{
	return ;
}

unsigned int	Food::getPosition( bool xy )
{
	return (_position[xy]);
}

bool			Food::checkPosition( double x, double y )
{
	// std::cout << "x == " << x << "\t y == " << y << std::endl;
	if (x >= _position[0] - 10 && x <= _position[0] + 10 && y >= _position[1] - 10 && y <= _position[1] + 10 ){
		std::cout << ">>> OK <<< " << std::endl;
		std::cout << "Food == { x == " << _position[0]
		<< "\t y == " << _position[1] << " }" << std::endl;
		return (1);
	}
	return (0);
}

void			Food::drawFood( sf::RenderWindow& win, assetManager& _assets )
{
	std::string	path("./images/foodParticule.png");

	_foodSprite.setOrigin(10, 10);
	_foodSprite.setTexture(_assets.getTexture(path));
	_foodSprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
	_foodSprite.setPosition(_position[0], _position[1]);
	_foodSprite.setRotation(0);
	win.draw(_foodSprite);
	return ;
}

unsigned int*	Food::getCoordinates( void )
{
	return (_position);
}
