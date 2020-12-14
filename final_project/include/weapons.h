#include<string>
#include<ctime>
#include<sstream>
/*
File: weapons.h
Brief: Retrieves weapon data
Author: Nicholas Preis
Assignment: Final Project
Date: 12/13/20
Credits:
    https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    https://www.boost.org/doc/libs/1_71_0/doc/html/boost_random/tutorial.html
*/

#include<iostream>
#include<fstream>
#include<boost/random/mersenne_twister.hpp>
#include<boost/random/uniform_int_distribution.hpp>
#include<boost/random/random_device.hpp>

using namespace std;

bool canWield(int minLevel, int currentLevel);
int damageOutput(int minLevel, int currentLevel, int minDamage);
int damageMulti();
void readData(std::ifstream& inFile);
string getWeapon(std::ifstream& inFile, string mWeaponName);
int getLevel(std::ifstream& inFile, string mWeaponName);
int getDamage(std::ifstream& inFile, string mWeaponName);
bool logData(std::ofstream& outFile, string message);