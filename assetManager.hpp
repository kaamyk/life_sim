#ifndef ASSET_HPP
# define ASSET_HPP

#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

class	assetManager
{
	private	:
		std::map<std::string, sf::Texture>	_textures;

	public	:
		assetManager( void );
		~assetManager( void );

		void			createNewTexture( const std::string path);
		sf::Texture&	getTexture( const std::string& path );
};

#endif