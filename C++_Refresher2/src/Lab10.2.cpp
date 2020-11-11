#include<iostream>
#include<pwd.h>
#include<unistd.h>
#include<libgen.h>
#include"logger.h"

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    string logValue{};
    string kmlValue;
    bool optErr = true;

    while((opt = getopt(argc, argv, "k:l:")) != EOF)
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

            default:
                optErr = true;
                break;
        }
    }

    if(kmlFlag && logFlag)
    {
        cout << "Flags are set!" << endl;
        if(logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            cout << "Option arguments aren't set." << endl;
        }
        else
        {
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "Flags - kmlFlag: " + kmlFlag;
                msg += " logFlag: " + logFlag;
                log(msg, programName, flog);
                optErr = false;
                flog.close();
            }
            else
            {
                cout << "Couldn't open " << logValue << endl;
                optErr = true;
            }
            
        }
    }
    else
    {
        cout << "Error: flags aren't set" << endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }
    
    cout << "optErr: " << optErr << endl;

    return EXIT_SUCCESS;
}