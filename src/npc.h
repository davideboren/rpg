#include "entity.h"

class NPC : public Entity {

	public:
		sf::Texture texture;
		std::string text;

		void update();
	
};
