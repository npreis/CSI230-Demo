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