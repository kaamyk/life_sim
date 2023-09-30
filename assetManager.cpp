#include "assetManager.hpp"

sf::Texture&	Simulation::getTexture( const std::string& path )
{
	std::cout << this->_textures.at(path).getSize() << std::endl;

	return (_textures.at(path));
}