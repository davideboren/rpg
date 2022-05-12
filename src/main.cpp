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
	player.setTile(2,1);

	const int level [] = {
		9, 10, 10, 10, 9,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0,
		0, 0, 0, 0, 0
	};

	//Collision map with padding on every side for OOB
	//Should probably dynamically generate this in tilemap
	const bool is_passable [6][7] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 1, 1, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 }
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

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			if(is_passable[player.cur_tile_y][player.cur_tile_x + 1])
				player.set_dest(0,-1,0);
			else
				player.set_dest(0,0,0);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			if(is_passable[player.cur_tile_y + 1][player.cur_tile_x + 2])
				player.set_dest(1,0,1);
			else
				player.set_dest(0,0,1);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			if(is_passable[player.cur_tile_y + 2][player.cur_tile_x + 1])
				player.set_dest(0,1,2);
			else
				player.set_dest(0,0,2);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			if(is_passable[player.cur_tile_y + 1][player.cur_tile_x])
				player.set_dest(-1,0,3);
			else
				player.set_dest(0,0,3);
		}


		player.update();
		
		window.clear();
		window.draw(map);
		window.draw(player);
		window.display();
	}

	return 0;
}
