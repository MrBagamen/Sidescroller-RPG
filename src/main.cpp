#include "Map.hpp"

#include <SFML/Graphics.hpp>

const sf::Color skyColor{162, 216, 252};

int main()
{
    sf::RenderWindow renderWindow({800, 600, 32}, "Sidescroller-Rpg",
                                  sf::Style::Close);

    Map map;
    int tile = 1;
    bool lmbdown = false;

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
                case sf::Keyboard::Num0:
                    tile = 0;
                    break;
                case sf::Keyboard::Num1:
                    tile = 1;
                    break;
                case sf::Keyboard::Num2:
                    tile = 2;
                    break;
                case sf::Keyboard::Num3:
                    tile = 3;
                    break;
                default: ;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed &&
                     event.mouseButton.button == sf::Mouse::Left)
            {
                lmbdown = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased &&
                     event.mouseButton.button == sf::Mouse::Left)
            {
                lmbdown = false;
            }
        }

        if (lmbdown)
        {
            int x = sf::Mouse::getPosition(renderWindow).x / 32;
            int y = sf::Mouse::getPosition(renderWindow).y / 32;
            map.tileAt(x, y).id = tile;
        }

        renderWindow.clear(skyColor);
        renderWindow.draw(map);
        renderWindow.display();
    }
}
