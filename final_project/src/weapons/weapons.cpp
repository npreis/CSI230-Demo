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