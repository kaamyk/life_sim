#include "../includes/Simulation.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_position {static_cast<float>(rand() % data.windowLength), static_cast<float>(rand() % data.windowHeight)},
							_rotation(0),
							_speed(3),
							_size(rand() % 100),
							_nbFoodEaten(0),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())
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

	for (unsigned char i = 0; i < 4; ++i){
		pt.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
		pt[i].setOrigin(2.5, 2.5);
		pt[i].setFillColor(sf::Color::White);
	}

	return ;
}

Creature::Creature( NeuralNetwork const& brain ): _fitness(0),
							_gradientDescent(0),
							_position {static_cast<float>(rand() % data.windowHeight), static_cast<float>(rand() % data.windowHeight)},
							_rotation(0),
							_speed(5),
							_size(rand() % 100),
							_nbFoodEaten(0),
							_birthTime(std::chrono::high_resolution_clock::now()),
							_timeLastEat(std::chrono::high_resolution_clock::now())

{
	_sensor = new Sensor();
	std::vector<unsigned int>	neuronCount;
	neuronCount.push_back(_sensor->getRayCount());
	neuronCount.push_back(6);
	neuronCount.push_back(4);
	_brain = new NeuralNetwork(brain);
	_brain->mutate(0.1f);
	_moves[0] = &Creature::moveUp;
	_moves[1] = &Creature::moveDown;
	_moves[2] = &Creature::moveRight;
	_moves[3] = &Creature::moveLeft;

	for (unsigned char i = 0; i < 4; ++i){
		pt.push_back(sf::RectangleShape(sf::Vector2f(5, 5)));
		pt[i].setOrigin(2.5, 2.5);
		pt[i].setFillColor(sf::Color::White);
	}

	return ;
}

Creature::~Creature( void )
{
	delete _sensor;
	delete _brain;
	return ;
}

bool	Creature::checkTime( std::chrono::seconds const _timeToDie )
{
	std::chrono::high_resolution_clock::time_point	t = std::chrono::high_resolution_clock::now();
	return (t - this->_timeLastEat >= _timeToDie);
}

void	Creature::drawCreature( sf::RenderWindow& win, assetManager& _assets, Simulation& sim )
{
	const std::string&	path("./images/SquareCreature.png");

	_sensor->drawRay(win, _assets, *this, sim);
	this->_creatureSprite.setOrigin((data.creatureSize) / 2, data.creatureSize / 2);
	this->_creatureSprite.setTexture(_assets.getTexture(path));
	this->_creatureSprite.setTextureRect(sf::IntRect(0, 0, data.creatureSize, data.creatureSize));
	this->_creatureSprite.setPosition(_position);
	// this->_creatureSprite.setRotation(_rotation);
	win.draw( this->_creatureSprite );
	for (unsigned char i = 0; i < pt.size(); i++){
		win.draw(pt[i]);
	}
	return ;
}

void	Creature::move( __uint8_t r ){
	(this->*_moves[r])();
}

void	Creature::moveUp( void )
{
	
	if (_position.y >= _speed)
		_position.y = _position.y - _speed;
	else
		_position.y = _position.y + float(data.windowHeight);


	float rot = _creatureSprite.getRotation();
	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 10.0f && rot <= 180.0f ){
		_creatureSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if ( rot > 180.0f && rot <= 350.0f ){
		_creatureSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if ( (rot > 0.0f && rot < 10.0f) || (rot > 350.0f && rot < 360.0f) ){
		_creatureSprite.setRotation(0.0f);
		// _rotation = 0;
	}
	return ;
}

void	Creature::moveDown( void )
{
	if (_position.y + _speed <= float(data.windowHeight))
		_position.y = _position.y + _speed;
	else
		_position.y = _position.y - float(data.windowHeight);


		
	float rot = _creatureSprite.getRotation();

	if ( rot == 360.0f )
		rot = 0.0f;
	if ( rot >= 190.0f && rot < 360.0f ){
		_creatureSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f;
	}
	else if ( rot >= 0.0f && rot <= 170.0f ){
		_creatureSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f;
	}
	else if ( rot > 170.0f && rot < float(100) ){
		_creatureSprite.setRotation(180.0f);
		// _rotation = 180.0f;
	}
	return ;
}

void	Creature::moveLeft( void )
{
	if (_position.x >= _speed)
		_position.x =_position.x - _speed;
	else
		_position.x = _position.x + float(data.windowLength);

		
	float rot = _creatureSprite.getRotation();

	if ((rot >= 0.0f && rot <= 90.0f) || (rot <= 360.0f && rot > 280.0f)){
		if (rot - 10.0f < 0.0f){
			rot = rot + 360.0f;
		}
		_creatureSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot > 90.0f && rot <= 260.0f){
		_creatureSprite.setRotation(rot + 10.0f);
		// _rotation = _rotation + 10.0f ;
	}
	else if (rot >= 260.0f && rot <= 280.0f){
		_creatureSprite.setRotation(270.0f);
		// _rotation = 270.0f;
	}
	return ;
}

void	Creature::moveRight( void )
{
	if (_position.x + _speed <= float(data.windowLength))
		_position.x = _position.x + _speed;
	else
		_position.x = _position.x - float(data.windowLength);

		
	float rot = _creatureSprite.getRotation();

	if ((rot >= 0.0f && rot < 80.0f)
		|| (rot >= 280.0f && rot <= 360.0f))
	{
		if (rot + 10.0f > 360.0f){
			_creatureSprite.setRotation((rot + 10.0f) - 360.0f);
			// _rotation = (_rotation + 10.0f) - 360.0f;
		}
		else{
			_creatureSprite.setRotation(rot + 10.0f);
			// _rotation = _rotation + 10.0f ;
		}
	}
	else if (rot > 100.0f && rot < 280.0f){
		_creatureSprite.setRotation(rot - 10.0f);
		// _rotation = _rotation - 10.0f ;
	}
	else if (rot >= 80.0f && rot <= 100.0f){
		_creatureSprite.setRotation(90.0f);
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

void			Creature::buildCheckPoints( void ){
	float	tmpx[2] = {_position.x + (data.creatureSize / 2), _position.x - (data.creatureSize / 2)};
	float	tmpy[2] = {_position.y + (data.creatureSize / 2), _position.y - (data.creatureSize / 2)};
	unsigned int i = 0;

	pt[i++].setPosition((tmpx[0] * cos(_rotation)) - (tmpy[0] * sin(_rotation)),
						(tmpx[0] * sin(_rotation)) - (tmpy[0] * cos(_rotation)));
	pt[i++].setPosition((tmpx[0] * cos(_rotation)) - (tmpy[1] * sin(_rotation)),
						(tmpx[0] * sin(_rotation)) - (tmpy[1] * cos(_rotation)));
	pt[i++].setPosition((tmpx[1] * cos(_rotation)) - (tmpy[0] * sin(_rotation)),
						(tmpx[1] * sin(_rotation)) - (tmpy[0] * cos(_rotation)));
	pt[i++].setPosition((tmpx[1] * cos(_rotation)) - (tmpy[1] * sin(_rotation)),
						(tmpx[1] * sin(_rotation)) - (tmpy[1] * cos(_rotation)));
}

void	Creature::eat( std::vector<Food *>& _food, std::vector<Creature *>& _population ){
		//  * static_cast<float>(sin(r * (3.14159265359f / 180)))
	//  * static_cast<float>(cos( r * (3.14159265359f / 180) ))
	// float	crPosx[] = {_position.x - (static_cast<float>(data.creatureSize / 2) * static_cast<float>(sin(_rotation * (3.14159265359f / 180)))),
	// 					_position.x + (static_cast<float>(data.creatureSize / 2) * static_cast<float>(sin(_rotation * (3.14159265359f / 180))))};

	// float	crPosy[] = {_position.y - (static_cast<float>(data.creatureSize / 2) * static_cast<float>(cos( _rotation * (3.14159265359f / 180) ))),
	// 					_position.y + (static_cast<float>(data.creatureSize / 2) * static_cast<float>(cos( _rotation * (3.14159265359f / 180) )))};

	buildCheckPoints();
	for (std::vector<Food *>::iterator it = _food.begin(); it != _food.end(); ++it){
		if ( (*it)->checkPositionCr( this->_position.x, this->_position.y, this->_rotation) ){
			_timeLastEat = std::chrono::high_resolution_clock::now();
			++_nbFoodEaten;
			if((*it)->getIsSpecial()){
				giveBirth(getBrain(), _population);
			}
			(*it)->getsEaten();
			return ;
		}
	}
}
