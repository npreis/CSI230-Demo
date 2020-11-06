/*
File: C++_Refresher1
Brief: Practicing C++ vectors and functions
Author: Nicholas Preis
Assignment: Lab 10.1
Date: 11/8/20
*/

#include"util.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctime>

using namespace std;

int main()
{
    vector <string> strVec;
    strVec.push_back("Bilbo");
    strVec.push_back("Gandalf");
    strVec.push_back("Pippin");
    strVec.push_back("Sam");
    strVec.push_back("Ring Wraith");
    strVec.push_back("Balrog");

    strVecCout(strVec);
    
    cout << "clue: setting srand in main" << endl;
    srand(time(NULL));
    int randStr = rand() % strVec.size();
    getRandStr(strVec, randStr);

    vector <double> dblVec;
    dblVec.push_back(3.14);
    dblVec.push_back(5.56);
    dblVec.push_back(7.72);
    dblVec.push_back(9);
    dblVec.push_back(-4);
    dblVec.push_back(99.99);
    dblVec.push_back(22);
    dblVec.push_back(30);

    dblVecCout(dblVec);
    calculatingDoubles(dblVec);

    string camelCase = "A little bird with a yellow bill";
    camelCaseConv(camelCase);

    return 0;
}