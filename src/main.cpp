#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mass.hpp"
#include "Calculations.hpp"



int main() {
   std::srand(std::time(0));
    std::cout << "Hello";
    sf::RenderWindow window(sf::VideoMode({2000, 2000}), "SFML works!"); //this command builds a window of size 800 x 800
    sf::Vector2f sizeinfo = (sf::Vector2f)window.getSize(); //unsigned 2d vector that stores window size info

    
    std::vector<Mass>masses;


    for(int i = 0; i < 3; i++)
    {
        float posx = std::rand() % (int)sizeinfo.x;
        float posy = std::rand() % (int)sizeinfo.y;
        float velx = 0;
        float vely = 0;
        float accx = 0;
        float accy = 0;
        float size_ = 4;
        float mass_ = size_ * 1e10; //mass proportional to size

        Mass m(posx , posy , velx , vely , accx , accy , size_ , mass_);
        masses.push_back(m);
    }

    
    Calculations calc(masses);

    while(window.isOpen())
    {
        
        
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear(sf::Color::Black);
        for(int i = 0; i < masses.size(); i++)
        {
            sf::CircleShape shape;
            Mass m = masses[i];
            shape.setRadius(m.get_mass() / 1e10); //set radius proportional to mass
            shape.setPosition(m.get_pos());
            shape.setFillColor(sf::Color::White);
            calc.calculate_and_update();
            calc.update_positions();
            window.draw(shape);
        }
       

        window.display();
    }
}