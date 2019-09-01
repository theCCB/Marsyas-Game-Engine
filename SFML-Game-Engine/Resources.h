#pragma once
#include <string>
#include <map>
#include <iostream>
#include "SFML/Graphics.hpp"

namespace mge
{
	class Resources
	{
	private:
		static std::map<std::string, sf::Texture*> loadedTextures;
	public:
		static bool loadTexture(std::string name, std::string path);
		static bool unloadTexture(std::string name);
		static sf::Texture getTexture(std::string name);
		static sf::Sprite* createSpriteFromTexture(std::string name);
		static sf::Sprite* createSpriteFromTexture(std::string name, sf::IntRect spriteFrame);
	};
}
