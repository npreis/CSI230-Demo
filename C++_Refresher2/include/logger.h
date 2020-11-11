/*
File: logger.h
Brief: Handles declaration of logging functionality
Author: Nicholas Preis
Assignment: Lab 10.2
Date: 11/11/20
*/

#pragma once
#include<string>
#include<fstream>
#include<unistd.h>

/*
Brief: Creates discrete syslog message
Date: 11/11/20
Return: Boolean indicating message was okay.
Param msg: string containing syslog message
Param logFile: ofstream, validation of logFile expected
*/
bool log(std::string msg, std::string programName, std::ofstream& logFile);