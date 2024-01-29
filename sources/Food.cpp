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

	sensPt = sf::RectangleShape(sf::Vector2f(8, 8));
	sensPt.setOrigin(sf::Vector2f(4.0f, 4.0f));
	sensPt.setFillColor(sf::Color::Green);

	PtPosFo = sf::RectangleShape(sf::Vector2f(10, 10));
	PtPosFo.setPosition(_foodSprite.getPosition());
	PtPosFo.setOrigin(sf::Vector2f(5.0f, 5.0f));
	PtPosFo.setFillColor(sf::Color::Red);
	
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

	sensPt = sf::RectangleShape(sf::Vector2f(8, 8));
	sensPt.setFillColor(sf::Color::Green);

	PtPosFo = sf::RectangleShape(sf::Vector2f(10, 10));
	PtPosFo.setPosition(_foodSprite.getPosition());
	PtPosFo.setOrigin(sf::Vector2f(5.0f, 5.0f));
	PtPosFo.setFillColor(sf::Color::Red);
	
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

void			Food::setPosition( sf::Vector2f const& np ){
	_foodSprite.setPosition(np);
}

void			Food::drawCheckPoints( sf::RenderWindow& win ){
	for (__uint8_t i = 0; i < 4; i++){
		win.draw(foodVrt[i]);
	}
}

void			Food::drawFood( sf::RenderWindow& win ){
	_isSpecial ? _foodSprite.setFillColor(sf::Color::Green) :  _foodSprite.setFillColor(sf::Color::White);

	// drawCheckPoints(win);
	
	// if (sensPt.size()){
	// 	for (__uint8_t i = 0; i < sensPt.size(); i++){
	// 		win.draw(sensPt[i]);
	// 	}
	// }
	win.draw(_foodSprite);
	win.draw(PtPosFo);
	return ;
}

void			Food::getsEaten( void ){
	setPosition(sf::Vector2f(rand() % data.windowLength, rand() % data.windowHeight));
	for (__uint8_t i = 0; i < 4; i++){
		foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
		PtPosFo.setPosition(_foodSprite.getPosition());
	}
}

bool			Food::checkPositionSe( float x, float y ){
	if (x >= foodVrt[0].getPosition().x && x <= foodVrt[2].getPosition().x
		&& y >= foodVrt[0].getPosition().y && y <= foodVrt[2].getPosition().y)
	{
		// buildCheckPointsSe(x, y);
		sensPt.setPosition(x, y);
		return (1);
	}
	return (0);
}

bool			Food::checkPositionCr( std::array<sf::RectangleShape, 4> const& crVrt ){
	for(__uint8_t i = 0; i < 4; i++ ){
		if (foodVrt[i].getPosition().x >= crVrt[0].getPosition().x && foodVrt[i].getPosition().x <= crVrt[2].getPosition().x
			&& foodVrt[i].getPosition().y >= crVrt[0].getPosition().y && foodVrt[i].getPosition().y <= crVrt[2].getPosition().y)
		{
			std::cout << "Position OK" << std::endl;
			return (1);
		}
	}
	return (0);
}

bool		Food::checkPositionCr1( sf::Vector2f CrSize, std::array<sf::RectangleShape, 4>& CrVrt ){
	for (__uint8_t i = 0; i < foodVrt.size(); i++){
		if ( bsp(CrSize, CrVrt, foodVrt[i].getPosition()) ){
			return (1);
		}
	}
	return (0);
}