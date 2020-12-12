#include<iostream>
#include<ctime>
#include<unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue{};
    string kmlValue;
    bool optErr = true;
    int currentLevel;

    while((opt = getopt(argc, argv, "k:l:c:")) != EOF)
    {
        switch(opt)
        {
            case 'k':
                kmlFlag = true;
                kmlValue = optarg;
                break;

            case 'l':
                logFlag = true;
                logValue = optarg;
                break;

            case 'c':
                currentLevel = (int)optarg;
                break;

            default:
                optErr = true;
                break;
        }
    }
    while(1)
    {
        cout << "hello" << endl;
        break;
    }
    return 0;
}