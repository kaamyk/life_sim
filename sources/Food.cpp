#include "../includes/Simulation.hpp"
#include "../includes/assetManager.hpp"
#include "../includes/Food.hpp"

Food::Food( void ): _position {(unsigned int)rand() % data.windowLength, (unsigned int)rand() % data.windowHeight}
{
	return ;
}

Food::Food( bool special ): _position {(unsigned int)rand() % data.windowLength, (unsigned int)rand() % data.windowHeight}, _isSpecial(special)
{
	return ;
}

Food::~Food( void )
{
	return ;
}

bool const &	Food::getIsSpecial( void ){
	return (_isSpecial);
}

unsigned int	Food::getPosition( bool xy ){
	return (_position[xy]);
}

unsigned int*	Food::getCoordinates( void ){
	return (_position);
}

void			Food::setPosition( unsigned int x, unsigned int y ){
	_position[0] = x;
	_position[1] = y;
}

void			Food::drawFood( sf::RenderWindow& win, assetManager& _assets )
{
	std::string	path;

	this->_isSpecial ? path = "./images/SquareSpecialFood.png" : path = "./images/SquareFood.png";

	_foodSprite.setOrigin(data.foodSize / 2, data.foodSize / 2);
	_foodSprite.setTexture(_assets.getTexture(path));
	_foodSprite.setTextureRect(sf::IntRect(0, 0, data.foodSize, data.foodSize));
	_foodSprite.setPosition(_position[0], _position[1]);
	_foodSprite.setRotation(0);
	win.draw(_foodSprite);
	return ;
}

void			Food::drawCheckPoints( sf::RenderWindow& win ){
	for (unsigned char i = 0; i < r.size(); ++i){
		win.draw(r[i]);
	}
}

void			Food::getsEaten( void ){
	setPosition(rand() % data.windowLength, rand() % data.windowHeight);
}

void			Food::buildCheckPoints(float crPosX[2], float crPosY[2], float foPosX[2], float foPosY[2]){
	(void) crPosX;
	(void) crPosY;

	if (r.size()){
		r.clear();
	}

	for (unsigned char i = 0; i < 8; ++i){
		r.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
		r[i].setOrigin(2.5, 2.5);
	}
	r[0].setPosition(crPosX[0], crPosY[0]);
	r[0].setFillColor(sf::Color::Cyan);
	r[1].setPosition(crPosX[1], crPosY[1]);
	r[1].setFillColor(sf::Color::Cyan);
	r[2].setPosition(crPosX[0], crPosY[1]);
	r[2].setFillColor(sf::Color::Cyan);
	r[3].setPosition(crPosX[1], crPosY[0]);
	r[3].setFillColor(sf::Color::Cyan);

	r[4].setPosition(foPosX[0], foPosY[0]);
	r[4].setFillColor(sf::Color::Green);
	r[5].setPosition(foPosX[1], foPosY[1]);
	r[5].setFillColor(sf::Color::Green);
	r[6].setPosition(foPosX[0], foPosY[1]);
	r[6].setFillColor(sf::Color::Green);
	r[7].setPosition(foPosX[1], foPosY[0]);
	r[7].setFillColor(sf::Color::Green);
}

bool			Food::checkPosition( float x, float y ){
	float	_creaturePosx[] = {x - static_cast<float>(data.creatureSize / 2), x + static_cast<float>(data.creatureSize / 2)};
	float	_creaturePosy[] = {y - static_cast<float>(data.creatureSize / 2), y + static_cast<float>(data.creatureSize / 2)};
	float	_foodPosx[] = {_position[0] - static_cast<float>(data.foodSize / 2), _position[0] + static_cast<float>(data.foodSize / 2)};
	float	_foodPosy[] = {_position[1] - static_cast<float>(data.foodSize / 2), _position[1] + static_cast<float>(data.foodSize / 2)};


	if ( (_creaturePosx[0] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1])
		|| (_creaturePosx[1] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1]) )
	{
		if ( (_creaturePosy[0] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosx[1])
		|| (_creaturePosy[1] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosy[1]) )
		{
			// buildCheckPoints(_creaturePosx, _creaturePosy, _foodPosx, _foodPosy);
			return (1);
		}
	}
	return (0);
}