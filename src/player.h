class Player : public sf::Sprite
{
	public:

		Player();

		int top, right, bottom, left;

		bool is_walking;
		unsigned int frame_counter;
		int anim_counter;
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

	private:

};
