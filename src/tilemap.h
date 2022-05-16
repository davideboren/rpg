#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
public:
	bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, const bool* passable_tiles, unsigned int width, unsigned int height);

	bool is_passable(int x, int y);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
    sf::Texture m_tileset;

	std::vector<std::vector<bool>> passable;
};
