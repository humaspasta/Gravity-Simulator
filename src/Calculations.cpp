#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Mass.hpp"

class Calculations
{
    const double G = 6.6743e-11;
    const double dt = 0.001; //time step

    std::vector<Mass> points;

    public:
    Calculations(std::vector<Mass> masses_in)
    {
       points = masses_in;
    }

    void update_positions()
    {
        for(int i = 0; i < points.size(); i++)
        {
            points[i].set_vel(points[i].get_velocity().x + points[i].get_acc().x * dt , points[i].get_velocity().y + points[i].get_acc().y * dt);
            points[i].set_pos(points[i].get_pos().x + points[i].get_velocity().x * dt , points[i].get_pos().y + points[i].get_velocity().y * dt);
        }
    }

    /*
    Calculates force between every pair of points and updates the acceleration vector of each accordingly
    */
    void calculate_and_update() //this is O(n^2)
    {
        for(int i = 0; i < points.size(); i++)
        {
            for(int j = 0; j < points.size(); j++)
            
                if(i != j)
                { //update all pairs to get net acceleration on each
                    sf::Vector2f force = calculate_force(points[i] , points[j]);
                    points[i].set_acc(m1.get_acc().x + (force.x / m1.get_mass()) , m1.get_acc().y + (force.y / m1.get_mass()));
                    points[j].set_acc(m2.get_acc().x + (force.x / m2.get_mass()) , m2.get_acc().y + (force.y / m2.get_mass())); //adds to current acceleration
                }
            }
        }
    }

    /*
    Function that returns a force vector between two masses
    */
    sf::Vector2f calculate_force(Mass m1 , Mass m2) 
    {
        float theta1 = calc_theta(m1, m2);

        float distance = dist(m1 , m2);
        float force = (G*m1.get_mass() * m2.get_mass()) / pow(distance , 2);

        sf::Vector2f vect = {force * std::cos(theta1) , force * std::sin(theta1)};

        return vect;
    }

    float dist(Mass m1, Mass m2)
    {
        return sqrtf(pow(m1.get_pos().x - m2.get_pos().x , 2) + pow(m1.get_pos().y - m2.get_pos().y , 2));
    }

    float norm(sf::Vector2f vector)
    {
        return sqrtf(pow(vector.x , 2) + pow(vector.y , 2));
    }

    float calc_theta(Mass m1, Mass m2)
    {
        sf::Vector2f pos1 = m1.get_pos();
        sf::Vector2f pos2 = m2.get_pos();
        
        sf::Vector2f delta = {std::max(pos1.x , pos2.x) - std::min(pos1.x,pos2.x) , std::max(pos1.y , pos2.y) - std::min(pos1.y , pos2.y)};
        
        float theta = std::atan2f(delta.y , delta.x);
        return theta;
    }
    

};