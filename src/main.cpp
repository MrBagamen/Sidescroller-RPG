#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow renderWindow(sf::VideoMode(800, 600, 32),
                                  "Sidescroller-Rpg", sf::Style::Close);

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

        renderWindow.clear();
        renderWindow.display();
    }
}
