#include <SFML/Graphics.hpp>
#include "entity.h"

class Player : public Entity
{
	public:

		Player();

		sf::Texture texture;

		bool is_walking;
		unsigned int frame_counter;
		unsigned int anim_counter;
		float walk_speed;

		int dir;

		int cur_tile_x, cur_tile_y;
		int dest_tile_x, dest_tile_y;
		sf::Vector2f dest_pos;

		sf::IntRect walk_frames [4][4];

		void update();

		void walk();

		void set_dest(int dx, int dy, int d);

		void setTile(int x, int y);

		std::pair<int,int> get_facing_tile();

	private:

};
