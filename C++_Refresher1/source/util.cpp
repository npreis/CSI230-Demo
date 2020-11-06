/*
File: C++_Refresher1
Brief: Practicing C++ vectors and functions
Author: Nicholas Preis
Assignment: Lab 10.1
Date: 11/8/20
Camel Case credit: https://www.geeksforgeeks.org/camel-case-given-sentence/
*/

#include"util.h"
#include <bits/stdc++.h>

/*
Brief: Prints out a string vector
Date: 11/8/20
Param: str vector
Return: void
*/
void strVecCout(vector <string> strVec)
{
    cout << "Dumping the vector of 6 elements: ";
    for(string s : strVec)
    {
       cout << s << " ";
    }
    cout << "\n";
}

/*
Brief: Gets a random string from a vector
Date: 11/8/20
Param: str vector, int
Return: void
*/
void getRandStr(vector <string> strVec, int randStr)
{
    cout << "calling getRandStr" << endl;
    cout << strVec.at(randStr);
    cout << "\n";
}

/*
Brief: Prints out a double vector
Date: 11/8/20
Param: double vector
Return: void
*/
void dblVecCout(vector <double> dblVec)
{
    cout << "Dumping a vector of doubles" << endl;
    for(double d : dblVec)
    {
        cout << d << " ";
    }
    cout << "\n";
}

/*
Brief: Prints the sum, average, and lowest number from the vector
Date: 11/8/20
Param: double vector
Return: void
*/
void calculatingDoubles(vector <double> dblVec)
{
    double sum = 0;
    double avg;
    double low = dblVec.front();

    for(double d : dblVec)
    {
        sum += d;
    }
    cout << "Sum: " << sum << "\n";
    
    avg = sum / dblVec.size();
    cout << "Avg: " << avg << "\n";

    for(double d : dblVec)
    {
        if(d < low)
        {
            low = d;
        }        
    }
    cout << "Low: " << low << "\n";
}

/*
Brief: Converts a string to camel case
Date: 11/8/20
Param: str
Return: void
*/
void camelCaseConv(string str)
{
    cout << "Calling camelCase with: " << str << "\n";

    int n = str.length();
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        if(str[i] == ' ')
        {
            str[i + 1] = toupper(str[i + 1]);
        }
        else
        {
            str[current++] = str[i];
        }
    }
    cout << "Message after camelCase: " << str.substr(0, current) << endl;
}