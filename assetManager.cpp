#include "assetManager.hpp"

assetManager::assetManager( void )
{
	return ;
}

assetManager::~assetManager( void )
{
	return ;
}

void	assetManager::createNewTexture( const std::string path )
{
	sf::Texture	texture;
	std::map<std::string, sf::Texture>::iterator	it;

	it = this->_textures.find(path);
	if (it != this->_textures.end())
	{
		std::cerr << "> Path already exists <" << std::endl;
		return ;
	}
	if (texture.loadFromFile(path) == 0)
	{
		std::cerr << "Texture load failed" << std::endl;
		return ;
	}
	this->_textures[path] = texture;
	return ;
}

sf::Texture&	assetManager::getTexture( const std::string& path )
{
	// std::cout << this->_textures.at(path).getSize() << std::endl;
	return (_textures.at(path));
}
