#include "Map.hpp"

#include <stdexcept>
#include <cassert>

constexpr int TILE_SIZE = 32;

Map::Map()
{
    if (!m_tileset.loadFromFile("res/tilesets/tileset.png"))
        throw std::runtime_error("Epic fail when trying to load tileset");
    resize(25, 19);
}

void Map::resize(int width, int height)
{
    m_width = width;
    m_height = height;

    m_tiles.resize(m_width * m_height, {0, true, true});
}

Tile& Map::tileAt(int x, int y)
{
#ifdef SSRPG_DEBUG
    assert(x >= 0 && x < m_width && y >= 0 && y < m_height);
#endif
    return m_tiles[y * m_width + x];
}

const Tile &Map::tileAt(int x, int y) const
{
#ifdef SSRPG_DEBUG
    assert(x >= 0 && x < m_width && y >= 0 && y < m_height);
#endif
    return m_tiles[y * m_width + x];
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates /*states*/) const
{
    sf::Sprite sprite(m_tileset);

    for (int y = 0; y < m_height; ++y)
    {
        for (int x = 0; x < m_width; ++x)
        {
            const Tile& t = tileAt(x, y);

            if (t.id == 0 || !t.visible)
                continue;

            sprite.setTextureRect({(t.id -1) * t.size, 0, t.size, t.size});
            sprite.setPosition(sf::Vector2f(x * t.size, y * t.size));
            target.draw(sprite);
        }
    }
}
