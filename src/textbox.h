#include <SFML/Graphics.hpp>
#include "entity.h"

class Textbox : public Entity {

	public:
		sf::Texture textbox_bg;

		Textbox();
		void update();

};
