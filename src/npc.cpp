#include "npc.h"
#include <iostream>

NPC::NPC(std::string str) :

	stand_frames
	{
		sf::IntRect(0,0,16,16),
		sf::IntRect(16,0,16,16),
	}

{
	
    if (!texture.loadFromFile("../gfx/slime.png")){
        std::cout << "Problem loading texture" << std::endl;
    }

	frame_counter = 0;
	anim_counter = 0;

	setTexture(texture);
	setTextureRect(stand_frames[anim_counter]);


}

void NPC::update(){

	if(frame_counter >= 30){
		anim_counter = (anim_counter + 1) % 2;
		setTextureRect(stand_frames[anim_counter]);
		frame_counter = 0;
	}
	frame_counter++;
	
}

void NPC::setTile(int x, int y){
    setPosition(x * 16, y * 16);
    cur_tile_x = x;
    cur_tile_y = y;
}

