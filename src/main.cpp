#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "npc.h"
#include "tilemap.h"

void check_inputs(Player* player, TileMap* map){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			if(map->is_passable(player->cur_tile_x,player->cur_tile_y - 1))
				player->set_dest(0,-1,0);
			else
				player->set_dest(0,0,0);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			if(map->is_passable(player->cur_tile_x + 1,player->cur_tile_y))
				player->set_dest(1,0,1);
			else
				player->set_dest(0,0,1);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			if(map->is_passable(player->cur_tile_x,player->cur_tile_y + 1))
				player->set_dest(0,1,2);
			else
				player->set_dest(0,0,2);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			if(map->is_passable(player->cur_tile_x - 1,player->cur_tile_y))
				player->set_dest(-1,0,3);
			else
				player->set_dest(0,0,3);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
			//std::cout << player->get_facing_tile().first << "," <<player->get_facing_tile().second << std::endl;
		}
}


int main()
{

	const int RENDER_WIDTH = 160;
	const int RENDER_HEIGHT = 144;

	const int SCREEN_WIDTH = RENDER_WIDTH * 2;
	const int SCREEN_HEIGHT = RENDER_HEIGHT * 2;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"Ducas Zone");
	window.setFramerateLimit(60);

	sf::View view;
	view.reset(sf::FloatRect(0,0,RENDER_WIDTH,RENDER_HEIGHT));

	window.setView(view);

	sf::Texture texture;
	if (!texture.loadFromFile("../gfx/gold.png"))
	{
		std::cout << "Problem loading texture";
	}

	std::vector<Entity*> entities;

	Player player;
	player.setTexture(texture);
	player.setTextureRect(sf::IntRect(0,0,16,16));
	player.setTile(5,4);
	entities.push_back(&player);

	NPC slime("Glop.");
	slime.setTile(8,4);
	entities.push_back(&slime);

	const int level [] = {
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 4, 9, 10, 10, 10, 10, 10, 9, 11,
		11, 8, 0, 0, 0, 0, 0, 3, 3, 11,
		11, 0, 0, 0, 0, 0, 0, 0, 3, 11,
		11, 0, 0, 0, 0, 0, 0, 3, 0, 11,
		11, 0, 0, 0, 0, 0, 0, 0, 0, 11,
		11, 0, 0, 0, 0, 0, 0, 0, 0, 11,
		11, 0, 0, 0, 6, 7, 0, 0, 0, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
	};

	const bool passable_tiles[] = {
		1, 1, 1, 0,
		0, 0, 1, 1,
		0, 0, 0, 0,
	};

	TileMap map;
	if (!map.load("../gfx/room.png", sf::Vector2u(16, 16), level, passable_tiles, 10, 9))
    	return -1;

	map.set_passable(8,4,false);

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

		check_inputs(&player, &map);

		window.clear();
		window.draw(map);

		for(int i = 0; i < entities.size(); i++){
			entities[i]->update();
			window.draw(*entities[i]);
		}

		window.display();
	}

	return 0;
}
