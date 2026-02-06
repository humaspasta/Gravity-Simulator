#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Mass.hpp"
#include "Calculations.hpp"


int main() {
   std::srand(std::time(0));
    sf::RenderWindow window(sf::VideoMode({5000, 5000}), "SFML works!"); //this command builds a window of size 800 x 800
    sf::Vector2f sizeinfo = (sf::Vector2f)window.getSize(); //unsigned 2d vector that stores window size info


    std::vector<Mass>masses;

    for(int i = 0; i < 10; i++)
    {
        float posx = std::rand() % (int)sizeinfo.x;
        float posy = std::rand() % (int)sizeinfo.y;
        float velx = 1;
        float vely = 1;
        float accx = 0;
        float accy = 0;
        float size_ = 10;
        float mass_ = size_ * 1e10; //mass proportional to size
        
        Mass m(posx , posy , velx , vely , accx , accy , size_ , mass_);
        masses.push_back(m);
        
       // step += 20;
    }

    // Mass big(sizeinfo.x/2 , sizeinfo.y / 2, 0, 0, 0, 0, 20, 20 * 1e10);
    // masses.push_back(big);
    
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
            sf::CircleShape com_shape;

            Mass m = masses[i];
            shape.setRadius(m.get_mass() / 1e10); //set radius proportional to mass
            shape.setPosition(m.get_pos());
            shape.setFillColor(sf::Color::White);
            
            com_shape.setRadius(4);
            com_shape.setPosition(calc.get_com());
            com_shape.setFillColor(sf::Color::Red);

            calc.calculate_and_update();
            calc.update_positions();
            calc.calculate_com();
            window.draw(shape);
            window.draw(com_shape);
        }
       

        window.display();
    }
}