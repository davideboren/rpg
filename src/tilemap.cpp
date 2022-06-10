#include <SFML/Graphics.hpp>
#include <vector>
#include "tilemap.h"
#include <iostream>

//This is lifted from the SFML documentation

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const bool* passable_tiles, unsigned int width, unsigned int height)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(width * height * 2 * 3);

	// resize collision matrix and populate with zeroes
	passable.resize(width + 2, std::vector<bool>(height + 2));
	passable.assign(width + 2, std::vector<bool>(0,height + 2));

	// populate the vertex array, with two tris per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's tris
			int index = (i + j * width) * 2 * 3;
			sf::Vertex* tri_top = &m_vertices[index];
			sf::Vertex* tri_bot = &m_vertices[index + 3];

			// define both tris
			tri_top[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			tri_top[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			tri_top[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			tri_top[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			tri_top[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			tri_top[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);

			//These two vertices are shared between both tris
			tri_bot[0] = tri_top[2];
			tri_bot[1] = tri_top[1];

			tri_bot[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			tri_bot[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);

			//populate collision matrix, leaving padding zeroes for OOB
			passable[i+1][j+1] = passable_tiles[tileNumber];
		}

	return true;
}

bool TileMap::is_passable(int x, int y){
	return passable[x + 1][y + 1];
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}
