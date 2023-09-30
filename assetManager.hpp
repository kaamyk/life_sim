#ifndef ASSET_HPP
# define ASSET_HPP

class	assetManager
{
	private	:
		std::map<std::string, sf::Texture&>	_textures;

	public	:
		sf::Texture&	getTexture( const std::string& path );
};

#endif