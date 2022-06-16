#include <SFML/Graphics.hpp>
#include "entity.h"

class Text : public Entity {

	public:
		sf::Font font;
		sf::Text text;

		Text(std::string);

		void update();

	private:
		int text_speed;
	
};
