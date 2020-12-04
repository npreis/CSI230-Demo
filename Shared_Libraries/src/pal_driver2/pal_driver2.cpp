/*
File: pal_driver2.cpp
Brief: Even Number Declarations
Author: Nicholas Preis
Assignment: Lab 12.1
Date: November 30, 2020
*/
#include "pal2.h"
#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int num = 0;
        cin >> num;

        if(isEven(num))
        {
            cout << "Number is even" << endl;
        }
        else
        {
            cout << "Number is odd" << endl;
        }
    }
    return 0;
}