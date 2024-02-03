#include "../includes/Food.hpp"

Food::Food( void ){
	for (unsigned int i = 0; i < s_data.ndFood; i++){
		particules.push_back(new s_particule);
	}
	_foodSprite.setOrigin(s_data.foodSize / 2, s_data.foodSize / 2);
	_foodSprite.setPosition(sf::Vector2f(rand() % s_data.windowLength, rand() % s_data.windowHeight));
	_foodSprite.setSize(sf::Vector2f(s_data.foodSize, s_data.foodSize));
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

Food::Food( bool special ):_isSpecial(special){
	_foodSprite.setOrigin(s_data.foodSize / 2, s_data.foodSize / 2);
	_foodSprite.setPosition(sf::Vector2f(rand() % s_data.windowLength, rand() % s_data.windowHeight));
	_foodSprite.setSize(sf::Vector2f(s_data.foodSize, s_data.foodSize));
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

Food::~Food( void ){
	return ;
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

void	Food::drawFood( sf::RenderWindow& win ){
	for (std::vector<Particule *>::iterator i = _particules.begin(); i != _particules.end(); i++){
		(*i)->drawParticule(win);
	}
}

// Modify to delete particule eated and Create a new one
void			Food::getsEaten( void ){
	setPosition(sf::Vector2f(rand() % s_data.windowLength, rand() % s_data.windowHeight));
	for (__uint8_t i = 0; i < 4; i++){
		foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
		PtPosFo.setPosition(_foodSprite.getPosition());
	}
}

bool			Food::checkPositionSe( float x, float y ){
	for(std::vector<Particule *>::iterator i = _particules.begin(); i < _paricules.end(); i++){
		if ( (*i)->checkPositionSe(x, y) ){
			return (1);
		}
	}
	return (0);
}

bool			Food::checkPositionCr( std::array<sf::RectangleShape, 4> const& crVrt ){
	for(std::vector<Particule *>::iterator i = _particules.begin(); i < _paricules.end(); i++){
		if ( (*i)->checkPositionCr(x, y) ){
			return (1);
		}
	}
	return (0);
}