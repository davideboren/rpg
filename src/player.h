class Player : public sf::Sprite
{
	public:

		Player();

		int top, right, bottom, left;
		void update();

		void walk(int dir);
		bool is_walking;
		unsigned int frame_counter;
		int anim_counter;
		float walk_speed;

		int dir;

		int curX, curY;
		int destX, destY;

		sf::IntRect walk_frames [4][4];

	private:

};
