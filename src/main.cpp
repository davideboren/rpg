#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.cpp"
#include "tilemap.cpp"

int main()
{

	const int RENDER_WIDTH = 80;
	const int RENDER_HEIGHT = 64;

	const int SCREEN_WIDTH = RENDER_WIDTH * 2;
	const int SCREEN_HEIGHT = RENDER_HEIGHT * 2;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"Ducas Zone");
	window.setFramerateLimit(60);

	sf::View view;
	view.reset(sf::FloatRect(0,0,RENDER_WIDTH,RENDER_HEIGHT));

	window.setView(view);

	sf::Texture texture;
	if (!texture.loadFromFile("gfx/gold.png"))
	{
		std::cout << "Problem loading texture";
	}

	Player player;
	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0,0,16,16));
	player.setPosition(32,32);

	const int level [] = {
		9,10,10,10,9,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};

	TileMap map;
	if (!map.load("gfx/room.png", sf::Vector2u(16, 16), level, 5, 4))
    	return -1;

	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed){
				window.close();
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)){
				window.close();
			}
		}

		player.update();
		
		window.clear();
		window.draw(map);
		window.draw(player);
		window.display();
	}

	return 0;
}
