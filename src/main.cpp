#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>


int main() {
   std::srand(std::time(0));

    std::cout << "Hello";
    sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!"); //this command builds a window of size 800 x 800
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::White);
    sf::Vector2f sizeinfo = (sf::Vector2f)window.getSize(); //unsigned 2d vector that stores window size info
    sf::Vector2f curr_pos = {0.0,0.0}; //
    sf::Vector2f velocity = {1.0,1.0};

    struct 
    { //struct that stores information about the motion of a point mass 
        sf::Vector2f position; //position, velocity, acceleration stored as 2d vectors. 
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        unsigned int size;
        unsigned int mass;

    } pnt;
    
        pnt.position = { (float)((std::rand() % 200) + 1), (float)((std::rand() % 200) + 1)};
        pnt.velocity = {1.f,1.f};
        pnt.acceleration = {0.5,0.5};
        pnt.size = 2.f;
        pnt.mass = 0.f;

    while(window.isOpen())
    {
        
   

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        if(pnt.position.x + pnt.size > sizeinfo.x || pnt.position.x - pnt.size < 0)
        {
            pnt.velocity.x = -1 * pnt.velocity.x;
        }
        
        if(pnt.position.y + pnt.size> sizeinfo.y || pnt.position.y - pnt.size < 0)
        {
            pnt.velocity.y = -1 * pnt.velocity.y;
        }

        pnt.position.x += pnt.velocity.x;
        pnt.position.y += pnt.velocity.y;

        std::cout << pnt.position.x <<std::endl;
        std::cout << pnt.position.y << std::endl;

        std::cout <<"" <<std::endl;

        
       
       window.clear(sf::Color::Black);
        shape.setPosition(pnt.position);
        window.draw(shape);
     
        window.display();
    }
}