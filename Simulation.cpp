/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

#include "Simulation.hpp"

Simulation::Simulation( void ): _nbMaxCreature(5), _timeToDie(10),
								_nbCreature(0)
{
	return ;
}

Simulation::~Simulation( void )
{
	return ;
}

unsigned int	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
}

void	Simulation::createNewTexture( const std::string path )
{
	sf::Texture	texture;
	std::map<std::string, sf::Texture&>::iterator	it;

	it = this->_textures.find(path);
	if (it != this->_textures.end())
		return ;
	if (texture.loadFromFile(path) == 0)
		std::cerr << "Texture load failed" << std::endl;
	this->_textures.insert(std::pair<std::string, sf::Texture&>(path, texture));
	return ;
}



void	Simulation::createNewCreature( void )
{
	Creature	newCreature;
	std::string	path("./images/creature.png");

	this->_population.push_back(newCreature);
	createNewTexture(path);
	updateNbCreature( 1 );
	return ;
}

bool	Simulation::checkNbCreature( void )
{
	return (this->_nbCreature > 0);
}

void	Simulation::updateNbCreature( bool a )
{
	a ? ++(this->_nbCreature) : --(this->_nbCreature);
	return ;
}

void	Simulation::checkLifeTimes( void )
{
	for(std::vector<Creature>::iterator i = _population.begin(); i != _population.end() && _population.size() != 0; ++i)
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
	const std::string&	path("./images/creature.png");

	for (std::vector<Creature>::iterator i = _population.begin(); i != _population.end() && _population.size() != 0; ++i)
		i->drawCreature(win, getTexture(path));
	return ;
}
