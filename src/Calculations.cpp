#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Mass.hpp"
#include "Calculations.hpp"

Calculations::Calculations(std::vector<Mass> &masses_in) 
{
    points = &masses_in;
    com = {0.f,0.f};
}

    void Calculations::update_positions()
    {
        for(int i = 0; i < points->size(); i++)
        {
            Mass& m = (*points)[i];
            
            m.set_vel(m.get_velocity().x + m.get_acc().x * dt , m.get_velocity().y + m.get_acc().y * dt ); //constant to scale speed is 1/10
            m.set_pos(m.get_pos().x + m.get_velocity().x * dt  , m.get_pos().y +m.get_velocity().y * dt);
        }
    }

    /*
    Calculates force between every pair of points and updates the acceleration vector of each accordingly
    */
    void Calculations::calculate_and_update() //this is O(n^2)
    {

        for(int i = 0; i < points->size(); i++)
        {
            for(int j = i + 1; j < points->size(); j++)
            {
                if(i != j)
                { //update all pairs to get net acceleration on each
                    Mass&m1 = (*points)[i];
                    Mass&m2 = (*points)[j];
                    
                    sf::Vector2f force = calculate_force(m1 , m2);
                    m1.set_acc(m1.get_acc().x + (force.x / m1.get_mass())  , m1.get_acc().y + (force.y / m1.get_mass()));
                    m2.set_acc(m2.get_acc().x  - (force.x / m2.get_mass())  , m2.get_acc().y  - (force.y / m2.get_mass())); //adds to current acceleration
                }
            }
        }
    }

    /*
    Function that returns a force vector between two masses
    */
   sf::Vector2f Calculations::calculate_force(Mass& m1, Mass& m2) const
{
    sf::Vector2f delta = m2.get_pos() - m1.get_pos(); // direction from m1 to m2
    float distance = sqrt(delta.x * delta.x + delta.y * delta.y);

    // prevent division by zero
    if (distance < 1e-5f) distance = 1e-5f;

    float magnitude = (G * m1.get_mass() * m2.get_mass()) / (distance * distance);

    // normalized direction * magnitude
    sf::Vector2f force = magnitude * (delta / distance);

    return force; // force on m1 due to m2
}


    float Calculations::dist(Mass& m1, Mass& m2) const
    {
        return sqrtf(pow(m1.get_pos().x - m2.get_pos().x , 2) + pow(m1.get_pos().y - m2.get_pos().y , 2));
    }


    float Calculations::norm(sf::Vector2f vector) const
    {
        return sqrtf(pow(vector.x , 2) + pow(vector.y , 2));
    }

    float Calculations::calc_theta(Mass& m1, Mass& m2) const
    {
        sf::Vector2f pos1 = m1.get_pos();
        sf::Vector2f pos2 = m2.get_pos();
        
        sf::Vector2f delta = {std::max(pos1.x , pos2.x) - std::min(pos1.x,pos2.x) , std::max(pos1.y , pos2.y) - std::min(pos1.y , pos2.y)};
        
        float theta = std::atan2f(delta.y , delta.x);
        return theta;
    }

    void Calculations::calculate_com() 
    {
        float t_mass = 0;
        float mx = 0;
        float my = 0;

        for(int i = 0; i < points->size(); i++)
        {
            Mass& pnt = (*points)[i];
            t_mass += pnt.get_mass();
            mx += pnt.get_pos().x * pnt.get_mass();
            my += pnt.get_pos().y * pnt.get_mass();
        }

       com.x = mx / t_mass;
       com.y = my / t_mass; 
    }

    sf::Vector2f Calculations::get_com() const
    {
        return com;
    }

  
    