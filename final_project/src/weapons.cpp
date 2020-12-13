#include "weapons.h"

bool canWield(int minLevel, int currentLevel)
{
    if(currentLevel >= minLevel)
    {
        return true;
    }
    return false;
}

int damageOutput(int minLevel, int currentLevel, int minDamage)
{
    int totalDamage;
    totalDamage = minDamage + (1.5 * (currentLevel - minLevel));

    return totalDamage;
}

int damageMulti()
{
    //std::time(0);

    boost::random::random_device gen;
    boost::random::uniform_int_distribution<> dist(1, 5);
    return dist(gen);
}

void readData(std::ifstream& inFile)
{
    string weaponName;
    string minLevel, minDamage;
    string strLine;

    if(!inFile)
    {
        cout << "File doesn't exist." << endl;
        return;
    }
    else
    {
        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            getline(s_stream, weaponName, ',');
            getline(s_stream, minLevel, ',');
            getline(s_stream, minDamage, ',');

            cout << weaponName << ", " << minLevel << ", " << minDamage << endl;
        }
    }
    
}

string getWeapon(std::ifstream& inFile, string mWeaponName)
{
    string weaponName;
    string minLevel, minDamage;
    string strLine;

    if(!inFile)
    {
        cout << "File doesn't exist." << endl;
        return "";
    }
    else
    {
        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            getline(s_stream, weaponName, ',');
            getline(s_stream, minLevel, ',');
            getline(s_stream, minDamage, ',');

            if(weaponName == mWeaponName)
            {
                cout << weaponName << endl;
                return weaponName;
            }
        }
        cout << "Weapon doesn't exist." << endl;
        return "";
    }
}