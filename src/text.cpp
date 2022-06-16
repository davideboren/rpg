#include <SFML/Graphics.hpp>
#include "text.h"
#include <iostream>

Text::Text(std::string box_text) {
	
	text_speed = 1;

	setPosition(16,96);

	if(!font.loadFromFile("../font/antidote.bdf")){
        std::cout << "Problem loading texture";
    }
    font.setSmooth(false);

	text.setFont(font);
    text.setString(box_text);
    text.setCharacterSize(11);
    text.setFillColor(sf::Color::Black);

}

void Text::update(){
	
}
