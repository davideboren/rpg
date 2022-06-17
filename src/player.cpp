#include <SFML/Graphics.hpp>
#include "player.h"
#include <math.h>
#include <iostream>

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

	if (!texture.loadFromFile("../gfx/gold.png"))
    {
        std::cout << "Problem loading texture";
    }

	setTexture(texture);
	setTextureRect(walk_frames[0][0]);

	is_walking = false;
	anim_counter = 0;
	walk_speed = 1;
	dir = 2;
}

void Player::update(){

	if(!is_walking){
		setTextureRect(walk_frames[dir][0]);
		frame_counter = 0;
		anim_counter = 0;
	}
	else{
		walk();
	}
}

void Player::set_dest(int dx, int dy, int d){
	if(!is_walking){
		dest_tile_y = cur_tile_y + dy;
		dest_tile_x = cur_tile_x + dx;
		dest_pos = sf::Vector2f(dest_tile_x * 16, dest_tile_y * 16);
		is_walking = true;
		frame_counter = 0;
		dir = d;
	}
}

void Player::walk(){

		setTextureRect(walk_frames[dir][anim_counter % 4]);
		if(frame_counter < 15){
			move(walk_speed * (dest_tile_x - cur_tile_x), walk_speed * (dest_tile_y - cur_tile_y));
		}
		else {
			move(walk_speed * (dest_tile_x - cur_tile_x), walk_speed * (dest_tile_y - cur_tile_y));
			frame_counter = 0;
			is_walking = false;
			cur_tile_x = dest_tile_x;
			cur_tile_y = dest_tile_y;
		}

		if(frame_counter % 8 == 1){
			anim_counter++;
		}
		frame_counter++;
}

void Player::setTile(int x, int y){
	setPosition(x * 16, y * 16);
	cur_tile_x = x;
	cur_tile_y = y;
}

std::pair<int,int> Player::get_facing_tile(){
	if(dir == 0){
		std::pair<int,int> output(cur_tile_x, cur_tile_y - 1);
		return output;
	}
	else if(dir == 1){
		std::pair<int,int> output(cur_tile_x + 1, cur_tile_y);
		return output;
	}
	else if(dir == 2){
		std::pair<int,int> output(cur_tile_x, cur_tile_y + 1);
		return output;
	}
	else if(dir == 3){
		std::pair<int,int> output(cur_tile_x - 1, cur_tile_y);
		return output;
	}

	std::pair<int,int> output(cur_tile_x, cur_tile_y + 1);
	return output;
}
