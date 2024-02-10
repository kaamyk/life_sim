#include "../includes/Particule.hpp"

Particule::Particule( void ):
        _position(sf::Vector2f(rand() % s_data.windowLength, rand() % s_data.windowHeight)),
        _isSpecial((rand() % 50) == 1),
        _sprite(sf::Vector2f(s_data.foodSize, s_data.foodSize))
{
    _sprite.setOrigin(sf::Vector2f(s_data.foodSize / 2, s_data.foodSize / 2));
    _sprite.setPosition(_position);
    _sprite.setFillColor(sf::Color::White);
    for(__uint8_t i = 0; i < 4; i++){
		// foodVrt[i].setPosition(_foodSprite.getTransform().transformPoint(_foodSprite.getPoint(i)));
        _partVtx[i] = sf::RectangleShape(sf::Vector2f(5, 5));
        _partVtx[i].setOrigin(sf::Vector2f(2.5f, 2.5f));
        _partVtx[i].setPosition( _sprite.getTransform().transformPoint(_sprite.getPoint(i)) );
        _partVtx[i].setFillColor( sf::Color::Red );
    }


    _checkPos.setFillColor(sf::Color::Green);
}

Particule::~Particule( void ){
    return ;
}


        /**********************/
        /*      GETTERS       */
        /**********************/


bool const &	Particule::getIsSpecial( void ) const {
	return (_isSpecial);
}

sf::Vector2f const&	Particule::getPosition( void ) const {
	return (_position);
}

        /************************/
        /*  POSITION CHECKERS   */
        /************************/

bool	Particule::checkPositionSe( float x, float y ){
        return (x >= _partVtx[0].getPosition().x && x <= _partVtx[2].getPosition().x
                && y >= _partVtx[0].getPosition().y && y <= _partVtx[2].getPosition().y);
//         {
//                 return (1);
//         }
//         return (0);
}

bool	Particule::checkPositionCr( sf::Vector2f crSize, std::array<sf::Vector2f, 4>& checkpointsPos ) {
        for (__uint8_t i = 0; i < 4; i++){
            if (checkpointsPos[i].x <= _position.x + (s_data.foodSize / 2) 
                && checkpointsPos[i].x >= _position.x - (s_data.foodSize / 2)
                && bsp(crSize, checkpointsPos, _position))
                {
                    return (1);
                }
        }
        return (0);
}

// bool			Food::checkPositionCr( std::array<sf::RectangleShape, 4> const& crVrt ){
// 	for(__uint8_t i = 0; i < 4; i++ ){
// 		if (foodVrt[i].getPosition().x >= crVrt[0].getPosition().x && foodVrt[i].getPosition().x <= crVrt[2].getPosition().x
// 			&& foodVrt[i].getPosition().y >= crVrt[0].getPosition().y && foodVrt[i].getPosition().y <= crVrt[2].getPosition().y)
// 		{
// 			std::cout << "Position OK" << std::endl;
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

        /***********************/
        /*      VISUALS        */
        /***********************/

void    Particule::setColorParticule( void ){
	_isSpecial ? _sprite.setFillColor(sf::Color::Green) : _sprite.setFillColor(sf::Color::White);
}

void    Particule::drawParticule( sf::RenderWindow& win ){
    win.draw(_sprite);
    // for (__uint8_t i = 0; i < 4; i++){
	// 	win.draw(_partVtx[i]);
	// }
}