#include "Map.hpp"

#include <SFML/Graphics.hpp>

const sf::Color skyColor{162, 216, 252};

int main()
{
    sf::RenderWindow renderWindow({800, 600, 32}, "Sidescroller-Rpg",
                                  sf::Style::Close);

    Map map;
    int tile = 1;
    bool lmbdown = false, rmbdown = false;

    while (renderWindow.isOpen())
    {
        sf::Event event;

        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Num1:
                    tile = 1;
                    break;
                case sf::Keyboard::Num2:
                    tile = 2;
                    break;
                case sf::Keyboard::Num3:
                    tile = 3;
                    break;
                case sf::Keyboard::Num4:
                    tile = 4;
                    break;
                default: ;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    lmbdown = true;
                else if (event.mouseButton.button == sf::Mouse::Right)
                    rmbdown = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                    lmbdown = false;
                else if (event.mouseButton.button == sf::Mouse::Right)
                    rmbdown = false;
            }
        }

        sf::Vector2i mp = sf::Mouse::getPosition(renderWindow);

        if (lmbdown)
            map.tileAt(mp.x / 32, mp.y / 32).id = tile;
        else if (rmbdown)
            map.tileAt(mp.x / 32, mp.y / 32).id = 0;

        renderWindow.clear(skyColor);
        renderWindow.draw(map);
        renderWindow.display();
    }
}
