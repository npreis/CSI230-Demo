#include<string>
#include<ctime>
#include<sstream>
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