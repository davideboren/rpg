#include "player.h"

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
	walk_speed = 0.75;
	dir = 2;
}

void Player::update(){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		walk(0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		walk(1);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		walk(2);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		walk(3);
	}
	else {
		setTextureRect(walk_frames[dir][0]);
		anim_counter = 0;
		frame_counter = 0;
	}
}

void Player::walk(int d){
	dir = d;
	switch(dir){
		case 0:
			setTextureRect(walk_frames[dir][anim_counter % 4]);
			move(0.0f, -walk_speed);
			break;
		case 1:
			setTextureRect(walk_frames[dir][anim_counter % 2]);
			move(walk_speed, 0);
			break;
		case 2:
			setTextureRect(walk_frames[dir][anim_counter % 4]);
			move(0.0f, walk_speed);
			break;
		case 3:
			setTextureRect(walk_frames[dir][anim_counter % 2]);
			move(-walk_speed, 0.0f);
			break;
		default:
			break;
	}
	if(frame_counter % 15 == 0){
		anim_counter++;
		frame_counter = 0;
	}
	frame_counter++;
}
