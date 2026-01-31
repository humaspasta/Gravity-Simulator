#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

class Mass
{
   
    struct Info
    { //struct that stores information about the motion of a point mass 
        sf::Vector2f position; //position, velocity, acceleration stored as 2d vectors. 
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        float size;
        float mass;
    };

    Info info;

    public:
    Mass(float posx , float posy, float velx, float vely, float accx, float accy, float size_, float mass_)
    {
        info.position = {posx , posy};
        info.velocity = {velx , vely};
        info.acceleration = {accx , accy};
        info.size = size_;
        info.mass = mass_;
    }

    void set_pos(float posx , float posy)
    {
        info.position.x = posx;
        info.position.y = posy;
    }

    sf::Vector2f get_pos()
    {
        return info.position;
    }

    void set_vel(float velx, float vely)
    {
        info.velocity.x = velx;
        info.velocity.y = vely;
    }

    sf::Vector2f get_velocity()
    {
        return info.velocity;
    }

    void set_acc(float accx , float accy)
    {
        info.acceleration.x = accx;
        info.acceleration.y = accy;
    }

    sf::Vector2f get_acc()
    {
        return info.acceleration;
    }

};