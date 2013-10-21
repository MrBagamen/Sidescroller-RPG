#include <SFML/Graphics.hpp>

const sf::Color skyColor{162, 216, 252};

int main()
{
    sf::RenderWindow renderWindow({800, 600, 32}, "Sidescroller-Rpg",
                                  sf::Style::Close);

    while (renderWindow.isOpen())
    {
        sf::Event event;

        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }
        }

        renderWindow.clear(skyColor);
        renderWindow.display();
    }
}
