#include"util.h"
#include <bits/stdc++.h>

void strVecCout(vector <string> strVec)
{
    cout << "Dumping the vector of 6 elements: ";
    for(string s : strVec)
    {
       cout << s << " ";
    }
    cout << "\n";
}

void getRandStr(vector <string> strVec, int randStr)
{
    cout << "calling getRandStr" << endl;
    cout << strVec.at(randStr);
    cout << "\n";
}

void dblVecCout(vector <double> dblVec)
{
    cout << "Dumping a vector of doubles" << endl;
    for(double d : dblVec)
    {
        cout << d << " ";
    }
    cout << "\n";
}

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