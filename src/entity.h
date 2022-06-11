#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
	public:
		virtual ~Entity() {}
		virtual void update() {}
};
