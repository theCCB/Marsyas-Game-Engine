#include "GameObject.h"
#include "Component.h"
#include "Scene.h"
#include "Collider.h"

namespace mge
{
	void GameObject::initVariables()
	{
		this->name = "GameObject";
		this->pos = Vector2f(0, 0);
		this->scale = Vector2f(1, 1);
		this->rotation = 0;
	}

	void GameObject::updateComponents()
	{
		// Adds the new components to the all components vector then
		// Starts the components even if they are enabled or not!
		for (auto c : newComponents)
		{
			components.push_back(c);
			c->start();

			Collider* collider = dynamic_cast<Collider*>(c);
			if (collider)
			{
				this->scene->addCollider(collider);
			}
		}
		newComponents.clear();

		// Updates all of the components (newly added too), if they are enabled
		for (auto c : components)
		{
			if (c->isActive())
				c->update();
		}
	}

	GameObject::GameObject(sf::String name, Vector2f pos)
	{
		this->initVariables();
		this->name = name;
		this->renderer.setTexture("default");
		this->renderer.setPosition(pos);
	}

	GameObject::GameObject(sf::String name, sf::String textureName, Vector2f pos)
	{
		this->initVariables();
		this->name = name;
		this->renderer.setTexture(textureName);
		this->pos = pos;
	}

	GameObject::GameObject(sf::String name, sf::String textureName, IntRect textureRect, Vector2f pos)
	{
		this->initVariables();
		this->name = name;
		this->renderer.setTexture(textureName, textureRect);
		this->pos = pos;
	}

	GameObject::~GameObject()
	{
		for (auto comp : components)
		{
			delete comp;
		}

	}

	void GameObject::init(Scene* scene)
	{
		this->scene = scene;
		this->renderer.setActive(true);
		for (auto comp : components)
		{
			Collider* col = dynamic_cast<Collider*>(comp);
			if (col)
			{
				Debug::log("Collider added");
				scene->addCollider(col);
			}
		}
	}

	void GameObject::update()
	{
		this->updateComponents();
		this->renderer.setPosition(this->pos);
		this->renderer.setScale(this->scale);
		this->renderer.setRotation(this->rotation);
	}

	void GameObject::render(sf::RenderWindow* window)
	{
		this->renderer.render(window);
	}

	void GameObject::setActive(bool active)
	{
		this->enabled = active;
	}
}