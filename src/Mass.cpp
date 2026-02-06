#include "Mass.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

    Mass::Mass(float posx , float posy, float velx, float vely, float accx, float accy, float size_, float mass_)
    {
        info.position = {posx , posy};
        info.velocity = {velx , vely};
        info.acceleration = {accx , accy};
        info.size = size_;
        info.mass = mass_;
    }

    void Mass::set_pos(float posx , float posy)
    {
        info.position.x = posx;
        info.position.y = posy;
    }

    sf::Vector2f Mass::get_pos() const
    {
        return info.position;
    }

    void Mass::set_vel(float velx, float vely)
    {
        info.velocity.x = velx;
        info.velocity.y = vely;
    }

    sf::Vector2f Mass::get_velocity() const
    {
        return info.velocity;
    }

    void Mass::set_acc(float accx , float accy)
    {
        info.acceleration.x = accx;
        info.acceleration.y = accy;
    }

    sf::Vector2f Mass::get_acc() const
    {
        return info.acceleration;
    }

    float Mass::get_mass() const
    {
        return info.mass;
    }

    
    float Mass::get_size() const
    {
        return info.size;
    }