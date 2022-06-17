#include "entity.h"
#include <SFML/Graphics.hpp>

class NPC : public Entity {

	public:

		NPC(std::string str);
		sf::Texture texture;

		std::string text;

		int cur_tile_x, cur_tile_y;

		int frame_counter;
		int anim_counter;

		sf::IntRect stand_frames [2];

		void update();

		void setTile(int x, int y);
	
};
