/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "../includes/Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(5), _timeToDie(30),
								_nbCreature(0), _nbFood(NBFOOD)
{
	return ;
}

Simulation::~Simulation( void )
{
	return ;
}

void			Simulation::loadTextures( void )
{
	_assets.createNewTexture("./images/creature.png");
	_assets.createNewTexture("./images/foodParticule.png");
	_assets.createNewTexture("./images/sensorRayOFF.png");
	_assets.createNewTexture("./images/sensorRayON.png");
}

unsigned int	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
}

Food*		Simulation::getFood( void )
{
	return (&_food[0]);
}

void	Simulation::createNewCreature( void )
{
	Creature	newCreature(WIN_H, WIN_L);
	std::string	path("./images/creature.png");

	this->_population.push_back(newCreature);
	updateNbCreature( 1 );
	return ;
}

bool	Simulation::checkNbCreature( void )
{
	return (this->_nbCreature != 0);
}

void	Simulation::updateNbCreature( bool a )
{
	a ? ++(this->_nbCreature) : --(this->_nbCreature);
	return ;
}

void	Simulation::checkLifeTimes( void )
{
	if (_population.size() == 0)
		return;
	for(std::vector<Creature>::iterator i = _population.begin(); i != _population.end(); ++i)
	{
		if (i->checkTime(this->_timeToDie))
		{
			std::cout << "In if erase()" << std::endl;
			this->updateNbCreature(0);
			this->_population.erase(i);
		}
	}
	return ;
}

void	Simulation::drawPopulation( sf::RenderWindow& win )
{
	if (_population.size() == 0)
		return;
	for (std::vector<Creature>::iterator i = _population.begin(); i != _population.end(); ++i)
	{
		std::vector<float> sensorInputs;
		sensorInputs.push_back(1.0f); //  >>> A remplacer par les vrais inputs  <<<
		sensorInputs.push_back(0.0f); //  >>> A remplacer par les vrais inputs  <<<
		sensorInputs.push_back(0.0f); //  >>> A remplacer par les vrais inputs  <<<
		sensorInputs.push_back(0.0f); //  >>> A remplacer par les vrais inputs  <<<
		std::vector<float>	outputs = i->feedForward(i->getSensor()->getState());

		for (size_t i = 0; i < outputs.size(); ++i){
			std::cout << "Creature.outputs[" << i << "] = " << outputs[i] << std::endl;
			std::cout << "(bool)Creature.outputs[" << i << "] = " << static_cast<bool>(outputs[i]) << std::endl;
		}
		
		if (outputs[0])
			i->moveUp();
		if (outputs[1])
			i->moveDown();
		if (outputs[2])
			i->moveRight();
		if (outputs[3])
			i->moveLeft();
		i->drawCreature(win, _assets, *this);
	}
	return ;
}

void	Simulation::drawAllFood( sf::RenderWindow& win )
{
	for (unsigned int i = 0; i < _nbFood; ++i)
		_food[i].drawFood(win, _assets);
	return ;
}
