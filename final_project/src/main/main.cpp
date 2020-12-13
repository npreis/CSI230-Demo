#include<iostream>
#include<ctime>
#include<unistd.h>
#include"weapons.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue{};
    string kmlValue;
    bool optErr = true;
    int currentLevel;

    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch(opt)
        {
            case 'k':
                kmlFlag = true;
                kmlValue = optarg;
                break;

            case 'l':
                logFlag = true;
                logValue = optarg;
                break;

            default:
                optErr = true;
                break;
        }
    }

    cout << "Insert your current level: ";
    cin >> currentLevel;

    cout << endl;

    while(1)
    {
        if(canWield(25, currentLevel))
        {
            cout << "Current damage output is: " 
            << damageOutput(25, currentLevel, 95) << endl;

            break;
        }
        cout << "You're too low level." << endl;
        break;
    }
    return 0;
}