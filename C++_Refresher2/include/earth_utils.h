/*
File: earth_utils.h
Brief: Marks coordinates on Google Earth
Author: Nicholas Preis
Assignment: Lab 10.2
Date: 11/11/20
*/

#pragma once
#include<string>
#include<fstream>

const std::string KMLHEADER1 = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
const std::string KMLHEADER2 = "<kml xmlns=\"http://www.opengis.net/kml/2.2\">";
const std::string KMLFOOTER = "</kml>";
const std::string KMLDOCSTART = "<Document>";
const std::string KMLDOCEND = "</Document>";

/*
Brief: Creates discrete syslog message
Date: 11/11/20
Return: integer for number of operations.
Param inFile: gets file to extract data from.
Param kmlFileName: string containing file name.
*/
int processCSV(std::ifstream& inFile, std::string kmlFileName);

/*
Brief: Creates discrete syslog message
Date: 11/11/20
Return: void.
Param kmlfile: gets the .kml file to output data to.
Param name: Name of a country and capital.
Param latitude: Latitude of capital.
Param longitude: Longitude of capital.
*/
void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude);