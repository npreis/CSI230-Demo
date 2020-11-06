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

void calculatingDoubles(vector <double> dblVec)
{
    double sum = 0;
    double avg;
    double low = dblVec.front();

    for(double d : dblVec)
    {
        sum += d;
    }
    cout << "Sum: " << sum << endl;
    
    avg = sum / dblVec.size();
    cout << "Avg: " << avg << endl;

    for(double d : dblVec)
    {
        if(d < low)
        {
            low = d;
        }        
    }
    cout << "Low: " << low << endl;
}