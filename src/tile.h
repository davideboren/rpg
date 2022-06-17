#include "entity.h"

class Tile {

public:

	Tile();
	Tile(Entity* e);

	Entity* entity;
	bool passable;
	bool interactable;
	bool door;
};
