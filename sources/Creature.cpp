#include "../includes/Simulation.hpp"

Creature::Creature( void ): _fitness(0),
							_gradientDescent(0),
							_position {static_cast<float>(rand() % data.windowLength), static_cast<float>(rand() % data.windowHeight)},
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
	_brain = new NeuralNetwork(neuronCount);
	_moves[0] = &Creature::moveUp;
	_moves[1] = &Creature::moveDown;
	_moves[2] = &Creature::moveRight;
	_moves[3] = &Creature::moveLeft;
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
	this->_creatureSprite.setPosition(this->_position[0], this->_position[1]);
	this->_creatureSprite.setRotation(_rotation);
	win.draw( this->_creatureSprite );
	return ;
}

void	Creature::move( __uint8_t r ){
	(this->*_moves[r])();
}

void	Creature::moveUp( void )
{
	if (_position[1] >= float(_speed))
		_position[1] = _position[1] - float(_speed);
	else
		_position[1] = _position[1] + float(data.windowHeight);

	if ( _rotation >= float(10) && _rotation <= float(180) ){
		_rotation = _rotation - float(10) ;
	}
	else if ( _rotation > float(180) && _rotation <= float(350) ){
		_rotation = _rotation + float(10) ;
	}
	else if ( (_rotation > 0 && _rotation < float(10)) || (_rotation > float(350) && _rotation < float(360)) ){
		_rotation = 0;
	}
	return ;
}

void	Creature::moveDown( void )
{
	if (_position[1] + float(_speed) <= float(data.windowHeight))
		_position[1] = _position[1] + float(_speed);
	else
		_position[1] = _position[1] - float(data.windowHeight);

	if ( _rotation == float(360) )
		_rotation = float(0);
	if ( _rotation >= float(190) && _rotation < float(360) ){
		_rotation = _rotation - float(10);
	}
	else if ( (_rotation >= float(0)) && _rotation <= float(170) ){
		_rotation = _rotation + float(10);
	}
	else if ( _rotation > float(170) && _rotation < float(100) ){
		_rotation = float(180);
	}
	return ;
}

void	Creature::moveLeft( void )
{
	if (_position[0] >= float(_speed))
		_position[0] =_position[0] - float(_speed);
	else
		_position[0] = _position[0] + float(data.windowLength);

	if ((_rotation >= float(0) && _rotation <= float(90)) || (_rotation <= float(360) && _rotation > float(280))){
		if (_rotation - float(10) < float(0)){
			_rotation = _rotation + float(360);
		}
		_rotation = _rotation - float(10) ;
	}
	else if (_rotation > float(90) && _rotation <= float(260)){
		_rotation = _rotation + float(10) ;
	}
	else if (_rotation >= float(260) && _rotation <= float(280)){
		_rotation = float(270);
	}
	return ;
}

void	Creature::moveRight( void )
{
	if (_position[0] + float(_speed) <= float(data.windowLength))
		_position[0] = _position[0] + float(_speed);
	else
		_position[0] = _position[0] - float(data.windowLength);

	if ((_rotation >= 0.0f && _rotation < 80.0f)
		|| (_rotation >= 280.0f && _rotation <= 360.0f))
	{
		if (_rotation + 10.0f > 360.0f){
			_rotation = float(_rotation + 10) - 360.0f;
		}
		else{
			_rotation = _rotation + float(10) ;
		}
	}
	else if (_rotation > 100.0f && _rotation < 280.0f){
		_rotation = _rotation - float(10) ;
	}
	else if (_rotation >= 80.0f && _rotation <= 100.0f){
		_rotation = float(90);
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

void	Creature::eat( std::vector<Food *> const& _food, std::vector<Food *>::iterator& it ){
	for (; it != _food.end(); ++it){
		if ( (*it)->checkPosition( this->_position[0], this->_position[1]) )
		{
			_timeLastEat = std::chrono::high_resolution_clock::now();
			++_nbFoodEaten;
			return ;
		}
	}
}

bool			Food::checkPosition( float x, float y ){
	float	_creaturePosx[] = {x - static_cast<float>(data.creatureSize / 2), x + static_cast<float>(data.creatureSize / 2)};
	float	_creaturePosy[] = {y - static_cast<float>(data.creatureSize / 2), y + static_cast<float>(data.creatureSize / 2)};
	unsigned int _foodPosx[] = {_position[0] - (data.foodSize / 2), _position[0] + (data.foodSize / 2)};
	unsigned int _foodPosy[] = {_position[1] - (data.foodSize / 2), _position[1] + (data.foodSize / 2)};

	if ( (_creaturePosx[0] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1])
		|| (_creaturePosx[1] >= _foodPosx[0] && _creaturePosx[0] <= _foodPosx[1]) )
	{
		if ( (_creaturePosy[0] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosx[1])
		|| (_creaturePosy[1] >= _foodPosy[0] && _creaturePosy[0] <= _foodPosy[1]) )
		{
			return (1);
		}
	}
	return (0);
}