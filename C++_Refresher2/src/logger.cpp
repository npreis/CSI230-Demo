/*
File: logger.cpp
Brief: Handles declaration of logging functionality
Author: Nicholas Preis
Assignment: Lab 10.2
Date: 11/11/20
*/

#include"logger.h"
#include<iostream>

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize - 1] = ' ';
    }

    std::string strHostName;
    int pid = getpid();

    if(logFile)
    {
        logFile << strTime << strHostName << " " << programName << "[" << pid << "]: " << msg << std::endl;
        std::cout << "true" << std::endl;
        return true;
    }
    else
    {
        std::cout << "false" << std::endl;
        return false;
    }
    
}