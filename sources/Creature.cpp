#include "../includes/Simulation.hpp"

Creature::Creature( void ): _gradientDescent(0),
							_speed(5),
							_size(s_data.creatureSize),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())
							// _size(rand() % 100),
							// _position {static_cast<float>(rand() % s_data.windowLength), static_cast<float>(rand() % s_data.windowHeight)},
							// _rotation(0),
{
	_sensor = new Sensor();
	std::vector<unsigned int>	neuronCount;
	neuronCount.push_back(_sensor->getRayCount());
	neuronCount.push_back(6);
	neuronCount.push_back(4);
	_brain = new NeuralNetwork(neuronCount);
	_moves[0] = &Creature::moveUp;
	_moves[1] = &Creature::moveDown;
	_moves[2] = &Creature::moveRight;
	_moves[3] = &Creature::moveLeft;

	// for (__uint8_t i = 0; i < 4; i++){
	// 	crVtx.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
	// 	crVtx[i].setOrigin(2.5, 2.5);
	// 	crVtx[i].setFillColor(sf::Color::White);
	// }
	crSprite = sf::RectangleShape(sf::Vector2f(_size, _size));
	crSprite.setPosition(static_cast<float>(rand() % s_data.windowLength), static_cast<float>(rand() % s_data.windowHeight));
	crSprite.setOrigin(_size / 2, _size / 2);

	for(__uint8_t i = 0; i < 4; i++){
		crVtx[i].setPosition(crSprite.getTransform().transformPoint(crSprite.getPoint(i)));
		crVtx[i].setFillColor(sf::Color::Red);
		crVtx[i].setSize(sf::Vector2f(10, 10));
		crVtx[i].setOrigin(sf::Vector2f(5.0f, 5.0f));
		crVtx[i].setRotation(0.0f);

		bspChck[i] = sf::Vector2f(5, 5);
	}

	return ;
}

Creature::Creature( NeuralNetwork* brain ):_gradientDescent(0),
							_speed(5),
							_size(s_data.creatureSize),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())
							// _size(rand() % 100),
							// _position {static_cast<float>(rand() % s_data.windowHeight), static_cast<float>(rand() % s_data.windowHeight)},
							// _rotation(0),

{
	_sensor = new Sensor();
	std::vector<unsigned int>	neuronCount;
	neuronCount.push_back(_sensor->getRayCount());
	neuronCount.push_back(6);
	neuronCount.push_back(4);
	_brain = new NeuralNetwork(brain);
	_brain->mutate(0.2f);
	_moves[0] = &Creature::moveUp;
	_moves[1] = &Creature::moveDown;
	_moves[2] = &Creature::moveRight;
	_moves[3] = &Creature::moveLeft;

	crSprite = sf::RectangleShape(sf::Vector2f(_size, _size));
	crSprite.setPosition(static_cast<float>(rand() % s_data.windowLength), static_cast<float>(rand() % s_data.windowHeight));
	crSprite.setOrigin(_size / 2, _size / 2);

	for(__uint8_t i = 0; i < 4; i++){
		crVtx[i].setPosition(crSprite.getTransform().transformPoint(crSprite.getPoint(i)));
		crVtx[i].setFillColor(sf::Color::Red);
		crVtx[i].setSize(sf::Vector2f(10, 10));
		crVtx[i].setOrigin(sf::Vector2f(5.0f, 5.0f));
		crVtx[i].setRotation(0.0f);
	}
}

Creature::~Creature( void ){
	delete _sensor;
	delete _brain;
}



/********************************************************/
/*						CHECKERS 						*/
/********************************************************/

bool	Creature::checkTime( std::chrono::seconds const _timeToDie ){
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_timeLastEat >= _timeToDie);
}

bool	Creature::checkLastPositions( void ){
	if (_lastPositions.size() < 100){
		return (0);
	}
	for (unsigned int i = 1; i < _lastPositions.size(); i++){
		if (_lastPositions[i].x != _lastPositions[i - 1].x || _lastPositions[i].y != _lastPositions[i - 1].y){
			_lastPositions.clear();
			return (0);
		}
	}
	return (1);
}



/********************************************************/
/*						DRAWING 						*/
/********************************************************/

void	Creature::drawCheckPoints( sf::RenderWindow& win ){
	for (__uint8_t i = 0; i < crVtx.size(); i++){
		win.draw(crVtx[i]);
	}
}

void	Creature::drawCreature( sf::RenderWindow& win ){
	// const std::string&	path("./images/SquareCreature.png");

	_sensor->drawRays(win);
	win.draw( crSprite );
	// for(__uint8_t i = 0; i < 4; i++){
	// 	sf::RectangleShape tmp(sf::Vector2f(5, 5));
    //     tmp.setFillColor(sf::Color::Red);
    //     tmp.setOrigin(2.5f, 2.5f);
    //     tmp.setPosition(bspChck[i]);
    //     win.draw(tmp);
	// }
}

void	Creature::updatePosition( void ){
	_lastPositions.push_back(crSprite.getPosition());
	updateCheckPoints();
}

void			Creature::updateCheckPoints( void ){
	for(__uint8_t i = 0; i < 4; i++){
		crVtx[i].setPosition(crSprite.getTransform().transformPoint(crSprite.getPoint(i)));
	}
}

void	Creature::updateSensors( Food& food ){
	_sensor->buildRays(*this, food);
}



/********************************************************/
/*						MOVEMENTS 						*/
/********************************************************/

void	Creature::move( __uint8_t r ){
	// std::cout << "Creature -> move" << std::endl;
	(this->*_moves[r])();
}

void	Creature::moveUp( void )
{
	sf::Vector2f	p(crSprite.getPosition());
	
	if (p.y >= _speed)
		p.y = p.y - _speed;
	else
		p.y = p.y + float(s_data.windowHeight);
	crSprite.setPosition(p);


	float rot = crSprite.getRotation();

	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 10.0f && rot <= 180.0f ){
		crSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if ( rot > 180.0f && rot <= 350.0f ){
		crSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if ( (rot > 0.0f && rot < 10.0f) || (rot > 350.0f && rot < 360.0f) ){
		crSprite.setRotation(0.0f);
		// _rotation = 0;
	}
	return ;
}

void	Creature::moveDown( void )
{
	sf::Vector2f	p(crSprite.getPosition());
	if (p.y + _speed <= float(s_data.windowHeight))
		p.y = p.y + _speed;
	else
		p.y = p.y - float(s_data.windowHeight);
	crSprite.setPosition(p);


	float rot = crSprite.getRotation();

	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 190.0f && rot < 360.0f ){
		crSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f;
	}
	else if ( rot >= 0.0f && rot <= 170.0f ){
		crSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f;
	}
	else if ( rot > 170.0f && rot < 100.0f ){
		crSprite.setRotation(180.0f);
		// _rotation = 180.0f;
	}
	return ;
}

void	Creature::moveLeft( void )
{
	sf::Vector2f	p(crSprite.getPosition());
	if (p.x >= _speed)
		p.x = p.x - _speed;
	else
		p.x = p.x + float(s_data.windowLength);
	crSprite.setPosition(p);

		
	float rot = crSprite.getRotation();

	if ((rot >= 0.0f && rot <= 90.0f) || (rot <= 360.0f && rot > 280.0f)){
		if (rot - 10.0f < 0.0f){
			rot = rot + 360.0f;
		}
		crSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot > 90.0f && rot <= 260.0f){
		crSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if (rot >= 260.0f && rot <= 280.0f){
		crSprite.setRotation(270.0f);
		// _rotation = 270.0f;
	}
	return ;
}

void	Creature::moveRight( void )
{
	sf::Vector2f	p(crSprite.getPosition());
	if (p.x + _speed <= float(s_data.windowLength))
		p.x = p.x + _speed;
	else
		p.x = p.x - float(s_data.windowLength);
	crSprite.setPosition(p);

		
	float rot = crSprite.getRotation();

	if ((rot >= 0.0f && rot < 80.0f)
		|| (rot >= 280.0f && rot <= 360.0f))
	{
		if (rot + 10.0f > 360.0f){
			crSprite.setRotation((rot + 10.0f) - 360.0f);
			// _rotation = (_rotation + 10.0f) - 360.0f;
		}
		else{
			crSprite.setRotation(rot + 10.0f);
			// _rotation = _rotation + 10.0f ;
		}
	}
	else if (rot > 100.0f && rot < 280.0f){
		crSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot >= 80.0f && rot <= 100.0f){
		crSprite.setRotation(90.0f);
		// _rotation = 90.0f;
	}
	return ;
}





std::vector<float> const&	Creature::feedForward( std::vector<float> sensorInputs ) const
{
	return (_brain->feedForward(sensorInputs));
	
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		// 	i->moveUp();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		// 	i->moveDown();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		// 	i->moveRight();
		// else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		// 	i->moveLeft();

}

Creature*	Creature::giveBirth( NeuralNetwork* brain ){
	NeuralNetwork*	n_NN(brain);
	return (new Creature(n_NN));
}

void	Creature::getVtxPos( std::array<sf::Vector2f, 4> *vtxPos ){
	for (__uint8_t i = 0; i < 4; i++){
		(*vtxPos)[i] = crVtx[i].getPosition();
	}
}

Creature*	Creature::eat( Food& food ){
	std::array<sf::Vector2f, 4>	vtxPos;
	bool checkRes[2] = {0, 0};

	getVtxPos(&vtxPos);
	bspChck = vtxPos;
	food.checkPositionCr(crSprite.getSize(), vtxPos, &checkRes[0]);

	if (checkRes[0]){
		std::cout << "Cr eat." << std::endl;
		_timeLastEat = std::chrono::high_resolution_clock::now();
		if (checkRes[1]){
			return (giveBirth(_brain));
		}
	}
	return (NULL);
}
