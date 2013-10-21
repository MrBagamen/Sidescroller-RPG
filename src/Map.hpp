#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

struct Tile {
    int id;
    bool visible;
    bool solid;

    static constexpr int size = 32;
};

class Map : public sf::Drawable {
public:
    Map();
    void resize(int width, int height);
    Tile& tileAt(int x, int y);
    const Tile& tileAt(int x, int y) const;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates /*states*/) const;
    sf::Texture m_tileset;
    std::vector<Tile> m_tiles;
    int m_width, m_height;
};

#endif // MAP_HPP
