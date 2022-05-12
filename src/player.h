class Player : public sf::Sprite
{
	public:

		Player();

		int top, right, bottom, left;
		void update();

		void walk();
		bool is_walking;
		unsigned int frame_counter;
		int anim_counter;
		float walk_speed;

		int dir;

		int cur_tile_x, cur_tile_y;
		int dest_tile_x, dest_tile_y;

		sf::IntRect walk_frames [4][4];

		void setTile(int x, int y);

	private:

};
