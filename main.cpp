#include "test/test.h"
#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    test();

    sf::RenderWindow window(sf::VideoMode(200, 200), "hello world!!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
