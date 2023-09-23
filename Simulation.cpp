/************************************************************************/
/*																		*/
/*																		*/
/*							LIFE SIMULATION								*/
/*					an artificial intelligence journey					*/
/*																		*/
/*																		*/
/************************************************************************/

Simulation::Simulation( void ): _nbMaxCreature(10), _timeToDie(10)
								_nbCreature(0);
{
	return ;
}

Simulation::~Simulation( void )
{
	return ;
}

size_t	Simulation::giveIndex( void )
{
	return ( this->_nbCreature );
}

void	Simulation::updateNbCreature( bool a )
{
	if (a)
		++(this->_nbCreature);
	else
		--(this->_nbCreature);
	return ;
}

void	Simulation::eraseCreature( std::vector::iterator i)
{
	this->_population.erase(i);
	return ;
}

void	Simulation::createNewCreature( void )
{
	Creature	newCreature;

	this->_population[_nbCreature - 1] = newCreature;
	return ;
}

bool	Simulation::checkNbCreature( void )
{
	return (this->_nbCreature > 0);
}

void	Simulation::checkLifeTimes( void )
{
	for(std::vector::iterator i = population.begin(); i != population.end(); ++i)
		if (this->_population[i].checkTime(this->_timeToDie) == 1)
			this->population[i].die();
}
