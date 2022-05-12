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
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			dest_tile_y = cur_tile_y - 1;
			is_walking = true;
			dir = 0;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			dest_tile_x = cur_tile_x + 1;
			is_walking = true;
			dir = 1;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			dest_tile_y = cur_tile_y + 1;
			is_walking = true;
			dir = 2;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			dest_tile_x = cur_tile_x - 1;
			is_walking = true;
			dir = 3;
		}
		else {
			setTextureRect(walk_frames[dir][0]);
			anim_counter = 0;
			frame_counter = 0;
		}
	}
	walk();
}

void Player::walk(){
	if(is_walking){
		switch(dir){
			case 0:
				setTextureRect(walk_frames[dir][anim_counter % 4]);
				if(getPosition().y > (dest_tile_y * 16 )){
					move(0.0f, -walk_speed);
				}
				else {
					is_walking = false;
					cur_tile_y = dest_tile_y;
				}
				break;
			case 1:
				setTextureRect(walk_frames[dir][anim_counter % 2]);
				if(getPosition().x < (dest_tile_x * 16)){
					move(walk_speed, 0);
				}
				else {
					is_walking = false;
					cur_tile_x = dest_tile_x;
				}
				break;
			case 2:
				setTextureRect(walk_frames[dir][anim_counter % 4]);
				if(getPosition().y < (dest_tile_y * 16 - 16)){
					move(0.0f, walk_speed);
				}
				else {
					is_walking = false;
					cur_tile_y = dest_tile_y;
				}
				break;
			case 3:
				setTextureRect(walk_frames[dir][anim_counter % 2]);
				if(getPosition().x > (dest_tile_x * 16 + 16)){
					move(-walk_speed, 0.0f);
				}
				else {
					is_walking = false;
					cur_tile_x = dest_tile_x;
				}
				break;
			default:
				break;
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
