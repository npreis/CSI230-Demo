#include"util.h"

void vecCout(vector <string> strVec)
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
    cout << endl;
}