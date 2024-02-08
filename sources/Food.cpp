#include "../includes/Food.hpp"

Food::Food( void ){
	for (unsigned int i = 0; i < s_data.nbFood; i++){
		_particules.push_back(new Particule());
	}
}

Food::~Food( void ){
	for (std::vector<Particule *>::iterator i = _particules.begin(); i < _particules.end(); i++){
		delete (*i);
	}
	_particules.clear();
}

std::vector<Particule *>&	Food::getParticules( void ){
	return (_particules);
}

void	Food::drawFood( sf::RenderWindow& win ){
	for (std::vector<Particule *>::iterator i = _particules.begin(); i != _particules.end(); i++){
		(*i)->drawParticule(win);
	}
}

// Modify to delete particule eated and Create a new one
bool	Food::getsEaten( Particule *ptParticule ){
	const bool	sp = ptParticule->getIsSpecial();

	delete (ptParticule);
	if (ptParticule != NULL)
		std::cerr << ">>> ERROR: particule delete failed ! <<<" << std::endl;
	return (sp);
}

bool			Food::checkPositionSe( float x, float y ){
	for(std::vector<Particule *>::iterator i = _particules.begin(); i < _particules.end(); i++){
		if ( (*i)->checkPositionSe(x, y) ){
			return (1);
		}
	}
	return (0);
}

void			Food::checkPositionCr( sf::Vector2f crSize, std::array<sf::Vector2f, 4>& crVrtPos, bool *res ){
	for(std::vector<Particule *>::iterator i = _particules.begin(); i < _particules.end(); i++){
		if ( (*i)->checkPositionCr(crSize, crVrtPos) ){
			res[0] = 1;
			res[1] = getsEaten(*i);
			_particules.erase(i);
		}
	}
}