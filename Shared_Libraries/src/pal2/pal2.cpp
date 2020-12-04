/*
File: pal2.h
Brief: Even Number Declarations
Author: Nicholas Preis
Assignment: Lab 12.1
Date: November 30, 2020
*/
#include "pal2.h"
#include <cmath>

bool isEven(int val)
{
    int num = val;
    bool result = false;

    if(abs(num) % 2 == 0)
    {
        result = true;
    }
    return result;
}