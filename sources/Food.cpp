#include "../includes/Food.hpp"

Food::Food( void ){
	for (unsigned int i = 0; i < s_data.nbFood; i++){
		_particules.push_back(new Particule());
	}
}

Food::~Food( void ){
	return ;
}

void	Food::drawFood( sf::RenderWindow& win ){
	for (std::vector<Particule *>::iterator i = _particules.begin(); i != _particules.end(); i++){
		(*i)->drawParticule(win);
	}
}

// Modify to delete particule eated and Create a new one
bool	Food::getsEaten( std::vector<Particule *>::iterator& itFood ){
	const bool	sp = (*itFood)->getIsSpecial();


	delete (*itFood);
	if (*itFood == NULL)
		_particules.erase(itFood);	
	else
		std::cerr << ">>> ERROR: delete failed ! <<<" << std::endl;
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

bool*			Food::checkPositionCr( sf::Vector2f crSize, std::array<sf::Vector2f, 4>& crVrtPos ){
	bool	res[2] = {0, 0};
	for(std::vector<Particule *>::iterator i = _particules.begin(); i < _particules.end(); i++){
		if ( (*i)->checkPositionCr(crSize, crVrtPos) ){
			res[0] = 1;
			res[1] = getsEaten(i);
		}
	}
	return (res);
}