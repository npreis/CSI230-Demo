#include"earth_utils.h"
#include<sstream>
#include<iostream>

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount{};

    if(!inFile)
    {
        return 0;
    }
    else
    {
        std::ofstream kmlFile;
        kmlFile.open(kmlFileName);

        if(kmlFile)
        {
            kmlFile << KMLHEADER1 << std::endl;
            kmlFile << KMLHEADER2 << std::endl;
            kmlFile << KMLDOCSTART << std::endl;

            getline(inFile, strLine);

            while(getline(inFile, strLine))
            {
                std::stringstream s_stream(strLine);
                std::getline(s_stream, strCountry, ',');
                std::getline(s_stream, strCapital, ',');
                std::getline(s_stream, strLat, ',');
                std::getline(s_stream, strLong, ',');
                
                std::string name = strCapital + ", " + strCountry;

                writePlacemark(kmlFile, name, strLat, strLong);
                recordCount ++;
            }

            kmlFile << KMLDOCEND << std::endl;
            kmlFile << KMLFOOTER << std::endl;
            kmlFile.close();
        }

        
    }

    return recordCount;
    
}

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << "<Placemark>" << std::endl;
    kmlFile << "<name>" << name << "</name>" << std::endl;
    kmlFile << "<Point><coordinates>" << latitude << "," << longitude << "</coordinates></Point>" << std::endl;
    kmlFile << "</Placemark>" << std::endl;
}