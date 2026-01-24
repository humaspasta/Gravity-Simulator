#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "Hello";
    sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!"); //this command builds a window of size 800 x 800
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Black);

    while(window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        
        window.display();
    }
}