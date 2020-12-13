#include<iostream>
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
    string weaponName;
    int currentLevel;
    int totalDamage;

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
        cout << "What weapon are you using? ";
        cin >> weaponName;

        ifstream inFile;
        inFile.open(kmlValue);
        getWeapon(inFile, weaponName);
        inFile.close();

        if(canWield(25, currentLevel))
        {
            totalDamage = damageOutput(25, currentLevel, 95) * damageMulti();
            cout << "The " << weaponName << "'s current damage output is: " << totalDamage << endl;

            break;
        }
        cout << "You're too low level." << endl;
        break;
    }
    return 0;
}