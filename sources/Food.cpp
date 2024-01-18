#include "../includes/Simulation.hpp"
#include "../includes/assetManager.hpp"
#include "../includes/Food.hpp"

Food::Food( void )
{
	_foodSprite.setOrigin(data.foodSize / 2, data.foodSize / 2);
	_foodSprite.setPosition(sf::Vector2f(rand() % data.windowLength, rand() % data.windowHeight));
	_foodSprite.setSize(sf::Vector2f(data.foodSize, data.foodSize));
	_foodSprite.setRotation(0.0f);

	for(__uint8_t i = 0; i < 4; i++){
		foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
		foodVrt[i].setFillColor(sf::Color::Green);
		foodVrt[i].setSize(sf::Vector2f(5, 5));
		foodVrt[i].setOrigin(sf::Vector2f(2.5, 2.5));
		foodVrt[i].setRotation(0.0f);
	}
	
	return ;
}

Food::Food( bool special ):_isSpecial(special)
{
	_foodSprite.setOrigin(data.foodSize / 2, data.foodSize / 2);
	_foodSprite.setPosition(sf::Vector2f(rand() % data.windowLength, rand() % data.windowHeight));
	_foodSprite.setSize(sf::Vector2f(data.foodSize, data.foodSize));
	_foodSprite.setRotation(0.0f);

	for(__uint8_t i = 0; i < 4; i++){
		foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
		foodVrt[i].setFillColor(sf::Color::Green);
		foodVrt[i].setSize(sf::Vector2f(5, 5));
		foodVrt[i].setOrigin(sf::Vector2f(2.5, 2.5));
		foodVrt[i].setRotation(0.0f);
	}
	
	return ;
}

Food::~Food( void )
{
	return ;
}

bool const &	Food::getIsSpecial( void ){
	return (_isSpecial);
}

sf::Vector2f const&	Food::getPosition( void ){
	return (_foodSprite.getPosition());
}

void			Food::setPosition( sf::Vector2f np ){
	_foodSprite.setPosition(np);
}

void			Food::drawFood( sf::RenderWindow& win )
{
	_isSpecial ? _foodSprite.setFillColor(sf::Color::Green) :  _foodSprite.setFillColor(sf::Color::White);

	for (__uint8_t i = 0; i < 4; i++){
		win.draw(foodVrt[i]);
	}
	
	if (sensPt.size()){
		for (unsigned char i = 0; i < sensPt.size(); ++i){
			win.draw(sensPt[i]);
		}
	}
	win.draw(_foodSprite);
	return ;
}

void			Food::drawCheckPoints( sf::RenderWindow& win ){
	for (unsigned char i = 0; i < foodVrt.size(); ++i){
		win.draw(foodVrt[i]);
	}
}

void			Food::getsEaten( void ){
	setPosition(sf::Vector2f(rand() % data.windowLength, rand() % data.windowHeight));
	for (__uint8_t i = 0; i < 4; i++){
		foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
	}
}

void			Food::buildCheckPoints(float x, float y ){
	if (sensPt.size()){
		sensPt.clear();
	}
	for (unsigned char i = 0; i < 4; ++i){
		sensPt.push_back(sf::RectangleShape(sf::Vector2f(8, 8)));
		sensPt[i].setOrigin(4, 4);
		sensPt[i].setFillColor(sf::Color::Green);
		sensPt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
	}

	sensPt.push_back(sf::RectangleShape(sf::Vector2f(8, 8)));
	sensPt[4].setFillColor(sf::Color::Green);
	sensPt[4].setPosition(x, y);
}

bool			Food::checkPositionSe( float x, float y ){
	if (x >= _foodSprite.getPosition().x && x <= _foodSprite.getPosition().x
		&& y >= _foodSprite.getPosition().y && y <= _foodSprite.getPosition().y)
	{
		buildCheckPoints(x, y);
		return (1);
	}
	return (0);
}

// void			Food::buildCheckPoints(float crPosX[3], float crPosY[3], float foPosX[2], float foPosY[2]){
// 	(void) crPosX;
// 	(void) crPosY;

// 	for (unsigned char i = 0; i < 13; ++i){
// 		r.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
// 		r[i].setOrigin(2.5, 2.5);
// 	}

// 	unsigned int i = 0;
	
// 	r[i].setPosition(foPosX[0], foPosY[0]);
// 	r[i++].setFillColor(sf::Color::Green);
// 	r[i].setPosition(foPosX[1], foPosY[1]);
// 	r[i++].setFillColor(sf::Color::Green);
// 	r[i].setPosition(foPosX[0], foPosY[1]);
// 	r[i++].setFillColor(sf::Color::Green);
// 	r[i].setPosition(foPosX[1], foPosY[0]);
// 	r[i++].setFillColor(sf::Color::Green);
	
// 	for(unsigned char io = 0;  io < 3; ++io){
// 		for (unsigned char ioo = 0; ioo < 3; ++ioo){
// 			r[i].setPosition(crPosX[io], crPosY[ioo]);
// 			r[i++].setFillColor(sf::Color::Magenta);
// 		}
// 	}
// }

bool			Food::checkPositionCr( std::array<sf::RectangleShape, 4> const& pt ){
	for(__uint8_t i = 0; i < 4; i++ ){
		if (foodVrt[i].getPosition().x >= pt[0].getPosition().x && foodVrt[i].getPosition().x <= pt[2].getPosition().x
			&& foodVrt[i].getPosition().y >= pt[2].getPosition().y && foodVrt[i].getPosition().y <= pt[0].getPosition().y)
		{
			std::cout << "Position OK" << std::endl;
			return (1);
		}
	}
	return (0);
}