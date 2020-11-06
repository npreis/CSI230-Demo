#include"util.h"

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