#include "../includes/Simulation.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_speed(5),
							_size(50),
							_nbFoodEaten(0),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())
							// _size(rand() % 100),
							// _position {static_cast<float>(rand() % data.windowLength), static_cast<float>(rand() % data.windowHeight)},
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
	// 	pt.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
	// 	pt[i].setOrigin(2.5, 2.5);
	// 	pt[i].setFillColor(sf::Color::White);
	// }
	CrSprite = sf::RectangleShape(sf::Vector2f(_size, _size));
	CrSprite.setPosition(static_cast<float>(rand() % data.windowLength), static_cast<float>(rand() % data.windowHeight));
	CrSprite.setOrigin(_size / 2, _size / 2);

	for(__uint8_t i = 0; i < 4; i++){
		pt[i].setPosition(CrSprite.getTransform().transformPoint(CrSprite.getPoint(i)));
		pt[i].setFillColor(sf::Color::Red);
		pt[i].setSize(sf::Vector2f(10, 10));
		pt[i].setOrigin(sf::Vector2f(5.0f, 5.0f));
		pt[i].setRotation(0.0f);
	}

	return ;
}

Creature::Creature( NeuralNetwork const& brain ): _fitness(0),
							_gradientDescent(0),
							_speed(5),
							_size(50),
							_nbFoodEaten(0),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())
							// _size(rand() % 100),
							// _position {static_cast<float>(rand() % data.windowHeight), static_cast<float>(rand() % data.windowHeight)},
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

	CrSprite = sf::RectangleShape(sf::Vector2f(_size, _size));
	CrSprite.setPosition(static_cast<float>(rand() % data.windowLength), static_cast<float>(rand() % data.windowHeight));
	CrSprite.setOrigin(_size / 2, _size / 2);

	for(__uint8_t i = 0; i < 4; i++){
		pt[i].setPosition(CrSprite.getTransform().transformPoint(CrSprite.getPoint(i)));
		pt[i].setFillColor(sf::Color::Red);
		pt[i].setSize(sf::Vector2f(10, 10));
		pt[i].setOrigin(sf::Vector2f(5.0f, 5.0f));
		pt[i].setRotation(0.0f);
	}
	
	return ;
}

Creature::~Creature( void ){
	delete _sensor;
	delete _brain;
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie ){
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_timeLastEat >= _timeToDie);
}

void	Creature::drawCheckPoints( sf::RenderWindow& win ){
	for (__uint8_t i = 0; i < pt.size(); i++){
		win.draw(pt[i]);
	}
}

void	Creature::drawCreature( sf::RenderWindow& win, Simulation& sim ){
	// const std::string&	path("./images/SquareCreature.png");

	_sensor->drawRay(win, *this, sim);
	win.draw( this->CrSprite );
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

void	Creature::updatePosition( void ){
	_lastPositions.push_back(CrSprite.getPosition());
	buildCheckPoints();
}

void			Creature::buildCheckPoints( void ){
	for(__uint8_t i = 0; i < 4; i++){
		pt[i].setPosition(CrSprite.getTransform().transformPoint(CrSprite.getPoint(i)));
	}
}

void	Creature::move( __uint8_t r ){
	// std::cout << "Creature -> move" << std::endl;
	(this->*_moves[r])();
}

void	Creature::moveUp( void )
{
	sf::Vector2f	p(CrSprite.getPosition());
	
	if (p.y >= _speed)
		p.y = p.y - _speed;
	else
		p.y = p.y + float(data.windowHeight);
	CrSprite.setPosition(p);


	float rot = CrSprite.getRotation();

	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 10.0f && rot <= 180.0f ){
		CrSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if ( rot > 180.0f && rot <= 350.0f ){
		CrSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if ( (rot > 0.0f && rot < 10.0f) || (rot > 350.0f && rot < 360.0f) ){
		CrSprite.setRotation(0.0f);
		// _rotation = 0;
	}
	return ;
}

void	Creature::moveDown( void )
{
	sf::Vector2f	p(CrSprite.getPosition());
	if (p.y + _speed <= float(data.windowHeight))
		p.y = p.y + _speed;
	else
		p.y = p.y - float(data.windowHeight);
	CrSprite.setPosition(p);


	float rot = CrSprite.getRotation();

	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 190.0f && rot < 360.0f ){
		CrSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f;
	}
	else if ( rot >= 0.0f && rot <= 170.0f ){
		CrSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f;
	}
	else if ( rot > 170.0f && rot < 100.0f ){
		CrSprite.setRotation(180.0f);
		// _rotation = 180.0f;
	}
	return ;
}

void	Creature::moveLeft( void )
{
	sf::Vector2f	p(CrSprite.getPosition());
	if (p.x >= _speed)
		p.x = p.x - _speed;
	else
		p.x = p.x + float(data.windowLength);
	CrSprite.setPosition(p);

		
	float rot = CrSprite.getRotation();

	if ((rot >= 0.0f && rot <= 90.0f) || (rot <= 360.0f && rot > 280.0f)){
		if (rot - 10.0f < 0.0f){
			rot = rot + 360.0f;
		}
		CrSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot > 90.0f && rot <= 260.0f){
		CrSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if (rot >= 260.0f && rot <= 280.0f){
		CrSprite.setRotation(270.0f);
		// _rotation = 270.0f;
	}
	return ;
}

void	Creature::moveRight( void )
{
	sf::Vector2f	p(CrSprite.getPosition());
	if (p.x + _speed <= float(data.windowLength))
		p.x = p.x + _speed;
	else
		p.x = p.x - float(data.windowLength);
	CrSprite.setPosition(p);

		
	float rot = CrSprite.getRotation();

	if ((rot >= 0.0f && rot < 80.0f)
		|| (rot >= 280.0f && rot <= 360.0f))
	{
		if (rot + 10.0f > 360.0f){
			CrSprite.setRotation((rot + 10.0f) - 360.0f);
			// _rotation = (_rotation + 10.0f) - 360.0f;
		}
		else{
			CrSprite.setRotation(rot + 10.0f);
			// _rotation = _rotation + 10.0f ;
		}
	}
	else if (rot > 100.0f && rot < 280.0f){
		CrSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot >= 80.0f && rot <= 100.0f){
		CrSprite.setRotation(90.0f);
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

void	Creature::giveBirth( NeuralNetwork const& brain, std::vector<Creature *>& _population ){
	_population.push_back(new Creature(brain));
}

void	Creature::eat( sf::RenderWindow& win, std::vector<Food *>& _food, std::vector<Creature *>& _population ){
	// buildCheckPoints();
	for (std::vector<Food *>::iterator it = _food.begin(); it != _food.end(); ++it){
		if ( (*it)->checkPositionCr( pt ) ){
			// std::cout << "eat" << std::endl;
			_timeLastEat = std::chrono::high_resolution_clock::now();
			++_nbFoodEaten;
			drawCheckPoints(win);
			if((*it)->getIsSpecial()){
				giveBirth(getBrain(), _population);
			}
			(*it)->getsEaten();
			return ;
		}
	}
}
