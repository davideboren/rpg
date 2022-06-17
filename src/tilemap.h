#include <SFML/Graphics.hpp>
#include "tile.h"

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* layout, const bool* passable_tiles, unsigned int width, unsigned int height);

	bool is_passable(int x, int y);

	void set_passable(int x, int y, bool pass);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
    sf::Texture m_tileset;

	std::vector<std::vector<Tile>> tiles;
};
