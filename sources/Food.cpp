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

void			Food::buildCheckPoints(float x, float y, float foPosX[2], float foPosY[2]){
	if (r.size()){
		r.clear();
	}

	for (unsigned char i = 0; i < 8; ++i){
		r.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
		r[i].setOrigin(2.5, 2.5);
	}

	r[0].setPosition(foPosX[0], foPosY[0]);
	r[0].setFillColor(sf::Color::Green);
	r[1].setPosition(foPosX[1], foPosY[1]);
	r[1].setFillColor(sf::Color::Green);
	r[2].setPosition(foPosX[0], foPosY[1]);
	r[2].setFillColor(sf::Color::Green);
	r[3].setPosition(foPosX[1], foPosY[0]);
	r[3].setFillColor(sf::Color::Green);

	r[4].setPosition(x, y);
	r[4].setFillColor(sf::Color::Cyan);
}

bool			Food::checkPositionSe( float x, float y ){
	float	_foodPosx[] = {_position[0] - static_cast<float>(data.foodSize / 2), _position[0] + static_cast<float>(data.foodSize / 2)};
	float	_foodPosy[] = {_position[1] - static_cast<float>(data.foodSize / 2), _position[1] + static_cast<float>(data.foodSize / 2)};


	for(__uint8_t i = 0; i < 3; ++i ){
		if (x >= _foodPosx[0] && x <= _foodPosx[1]
			&& y >= _foodPosy[0] && y <= _foodPosy[1])
		{
			buildCheckPoints(x, y, _foodPosx, _foodPosy);
			return (1);
		}
	}

	return (0);
}

void			Food::buildCheckPoints(float crPosX[3], float crPosY[3], float foPosX[2], float foPosY[2]){
	(void) crPosX;
	(void) crPosY;

	for (unsigned char i = 0; i < 13; ++i){
		r.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
		r[i].setOrigin(2.5, 2.5);
	}

	unsigned int i = 0;
	
	r[i].setPosition(foPosX[0], foPosY[0]);
	r[i++].setFillColor(sf::Color::Green);
	r[i].setPosition(foPosX[1], foPosY[1]);
	r[i++].setFillColor(sf::Color::Green);
	r[i].setPosition(foPosX[0], foPosY[1]);
	r[i++].setFillColor(sf::Color::Green);
	r[i].setPosition(foPosX[1], foPosY[0]);
	r[i++].setFillColor(sf::Color::Green);
	
	for(unsigned char io = 0;  io < 3; ++io){
		for (unsigned char ioo = 0; ioo < 3; ++ioo){
			r[i].setPosition(crPosX[io], crPosY[ioo]);
			r[i++].setFillColor(sf::Color::Magenta);
		}
	}
}

bool			Food::checkPositionCr( float x, float y, float r ){
	//  * static_cast<float>(sin(r * (3.14159265359f / 180)))
	//  * static_cast<float>(cos( r * (3.14159265359f / 180) ))
	( void )r;
	float	crPosx[] = {x - (static_cast<float>(data.creatureSize / 2)),
						x,
						x + (static_cast<float>(data.creatureSize / 2))};

	float	crPosy[] = {y - (static_cast<float>(data.creatureSize / 2)),
						y,
						y + (static_cast<float>(data.creatureSize / 2))};

	float	_foodPosx[] = {_position[0] - static_cast<float>(data.foodSize / 2), _position[0] + static_cast<float>(data.foodSize / 2)};
	float	_foodPosy[] = {_position[1] - static_cast<float>(data.foodSize / 2), _position[1] + static_cast<float>(data.foodSize / 2)};


	// buildCheckPoints(crPosx, crPosy, _foodPosx, _foodPosy);
	for(__uint8_t i = 0; i < 3; i++ ){
		if (crPosx[i] >= _foodPosx[0] && crPosx[i] <= _foodPosx[1]
			&& crPosy[i] >= _foodPosy[0] && crPosy[i] <= _foodPosy[1])
		{
			return (1);
		}
	}

	return (0);
}