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

    vecCout(strVec);
    
    cout << "clue: setting srand in main" << endl;
    srand(time(NULL));
    int randStr = rand() % strVec.size();
    getRandStr(strVec, randStr);

    return 0;
}