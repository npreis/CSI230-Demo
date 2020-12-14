/*
File: main.cpp
Brief: Makes program run
Author: Nicholas Preis
Assignment: Final Project
Date: 12/13/20
Credits:
    https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    https://www.boost.org/doc/libs/1_71_0/doc/html/boost_random/tutorial.html
*/

#include<iostream>
#include<unistd.h>
#include"weapons.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool csvFlag{false};
    bool logFlag{false};
    string logValue{};
    string csvValue;
    bool optErr = true;
    string weaponName;
    int minLevel;
    int minDamage;
    int currentLevel;
    int totalDamage;
    string outputMessage;

    while((opt = getopt(argc, argv, "c:l:")) != EOF)
    {
        switch(opt)
        {
            case 'c':
                csvFlag = true;
                csvValue = optarg;
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

    while(1)
    {
        cout << "What weapon are you using? ";
        cin >> weaponName;

        ifstream inFile;
        inFile.open(csvValue);
        weaponName = getWeapon(inFile, weaponName);
        inFile.close();

        inFile.open(csvValue);
        minLevel = getLevel(inFile, weaponName);
        inFile.close();

        if(canWield(minLevel, currentLevel) && weaponName != "")
        {
            inFile.open(csvValue);
            minDamage = getDamage(inFile, weaponName);
            inFile.close();

            totalDamage = damageOutput(minLevel, currentLevel, minDamage) * damageMulti();
            outputMessage =  "The " + weaponName + "'s current damage output is: " + to_string(totalDamage);

            ofstream outFile;
            outFile.open(logValue);
            logData(outFile, outputMessage);
            outFile.close();
        }
        else
        {
            cout << "Either the weapon doesn't exist, or you're too low level." << endl;
        }
    }
    return 0;
}