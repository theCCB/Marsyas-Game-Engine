#pragma once
#include "Renderer.h"
#include "Math.h"

namespace mge
{
	class SpriteRenderer : public Renderer
	{
	private:
		sf::String textureName;
		IntRect textureRect;
		sf::Sprite* sprite;

	public:
		SpriteRenderer(sf::String textureName);
		SpriteRenderer(sf::String textureName, IntRect textureRect);
		~SpriteRenderer();

		void render(sf::RenderWindow& window, Camera& camera) override;

		void setActive(bool isActive) override;

		void setTexture(sf::String textureName);
		void setTexture(sf::String textureName, IntRect textureRect);
		void setTexureRect(IntRect textureRect);

		sf::FloatRect getGlobalBounds();

		void resetSprite();

		Vector2f getSize() override;
		FloatRect getBoundingBox() override;
	};
}

