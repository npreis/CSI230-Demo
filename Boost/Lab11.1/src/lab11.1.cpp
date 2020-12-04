/*
File: Boost Random
Brief: Using Boost Random to generate a random number in a range
Author: Nicholas Preis
Assignment: Lab 11.1
Date: 11/15/20
Credits:
https://www.boost.org/doc/libs/1_71_0/doc/html/boost_random/tutorial.html
*/

#include <boost/random/random_device.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <iostream>

int roll_die() 
{
    boost::random::random_device gen;
    boost::random::uniform_int_distribution<> dist(1, 20);
    return dist(gen);
}

int main() 
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << roll_die() << std::endl;
    }
    return 0;
}