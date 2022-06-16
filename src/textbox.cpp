#include <SFML/Graphics.hpp>
#include "textbox.h"
#include <iostream>

Textbox::Textbox() {
	
	if (!textbox_bg.loadFromFile("../gfx/textbox.png")){
		std::cout << "Problem loading texture" << std::endl;
	}

	setTexture(textbox_bg);
	setTextureRect(sf::IntRect(0,0,128,48));
	setPosition(16,96);

}

void Textbox::update(){
	
}
