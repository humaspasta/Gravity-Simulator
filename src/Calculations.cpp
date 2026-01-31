#include <iostream>
#include "Mass.cpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>

class Calculations
{
    const double G = 6.6743e-11;
    
    std::vector<Mass> masses;
    public:
    Calculations(std::vector<Mass>masses_in)
    {
       masses = masses_in;
    }

    void calculate_and_update() //this is O(n^2)
    {

    }

    float calculate_force(Mass m1 , Mass m2)
    {

        dist(m1 , m2);
    }

    float dist(Mass m1, Mass m2)
    {
        return sqrtf(pow(m1.get_pos().x - m2.get_pos().x , 2) + pow(m1.get_pos().y - m2.get_pos().y , 2));
    }

};