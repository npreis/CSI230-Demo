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
    string minLevel;
    string minDamage;
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
        weaponName = getWeapon(inFile, weaponName);
        inFile.close();

        inFile.open(kmlValue);
        minLevel = getLevel(inFile, weaponName);
        inFile.close();

        if(canWield(25, currentLevel) && weaponName != "")
        {
            inFile.open(kmlValue);
            minDamage = getDamage(inFile, weaponName);
            inFile.close();

            totalDamage = damageOutput(25, currentLevel, 95) * damageMulti();
            cout << "The " << weaponName << "'s current damage output is: " << totalDamage << endl;

            break;
        }
        cout << "Either the weapon doesn't exist, or you're too low level." << endl;
        break;
    }
    return 0;
}