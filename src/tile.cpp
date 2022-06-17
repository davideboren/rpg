#include "tile.h"

Tile::Tile(){
	passable = true;
	interactable = false;
	door = false;
}

Tile::Tile(Entity* e){
	passable = false;
	interactable = true;
	door = false;

	entity = e;
}
