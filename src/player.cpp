#include "player.h"
#include <math.h>

Player::Player() :

	walk_frames
	{
		{
			sf::IntRect(64,0,16,16),
			sf::IntRect(80,0,16,16),
			sf::IntRect(64,0,16,16),
			sf::IntRect(48,0,16,16)
		},
		{
			sf::IntRect(128,0,16,16),
			sf::IntRect(144,0,16,16),
			sf::IntRect(128,0,16,16),
			sf::IntRect(144,0,16,16),
		},
		{
			sf::IntRect(16,0,16,16),
			sf::IntRect(32,0,16,16),
			sf::IntRect(16,0,16,16),
			sf::IntRect(0,0,16,16)
		},
		{
			sf::IntRect(96,0,16,16),
			sf::IntRect(112,0,16,16),
			sf::IntRect(96,0,16,16),
			sf::IntRect(112,0,16,16),
		},
	}

{
	is_walking = false;
	anim_counter = 0;
	walk_speed = 1;
	dir = 2;
}

void Player::update(){

	if(!is_walking){
		setTextureRect(walk_frames[dir][0]);
		anim_counter = 0;
		frame_counter = 0;
	}
	walk();
}

void Player::set_dest(int dx, int dy, int d){
	if(!is_walking){
		dest_tile_y = cur_tile_y + dy;
		dest_tile_x = cur_tile_x + dx;
		dest_pos = sf::Vector2f(dest_tile_x * 16, dest_tile_y * 16);
		is_walking = true;
		dir = d;
	}
}

void Player::walk(){
	if(is_walking){

		setTextureRect(walk_frames[dir][anim_counter % 4]);
		if(getPosition() != dest_pos){
			move(walk_speed * (dest_tile_x - cur_tile_x), walk_speed * (dest_tile_y - cur_tile_y));
		}
		else {
			is_walking = false;
			cur_tile_x = dest_tile_x;
			cur_tile_y = dest_tile_y;
		}

		if(frame_counter % 10 == 0){
			anim_counter++;
			frame_counter = 0;
		}

	frame_counter++;
		
	}
}

void Player::setTile(int x, int y){
	setPosition(x * 16, y * 16);
	cur_tile_x = x;
	cur_tile_y = y;
}
