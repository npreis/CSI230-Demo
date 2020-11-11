#include<iostream>
#include<pwd.h>
#include<unistd.h>
#include<libgen.h>

using namespace std;

int main(int argc, char* argv[])
{
    int opt{};
    bool countFlag{false};
    bool logFlag{false};
    int count{};
    string logValue{};
    bool optErr = true;

    while((opt = getopt(argc, argv, "c:l:")) != EOF)
    {
        switch(opt)
        {
            case 'c':
                countFlag = true;
                count = atoi(optarg);
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

    cout << "Flags - countFlag: " << countFlag << " logFlag: " << logFlag << endl;

    if(countFlag && logFlag)
    {
        cout << "Flags are set!" << endl;
        if(logValue.empty() || count == 0)
        {
            optErr = true;
            cout << "Option arguments aren't set." << endl;
        }
        else
        {
            optErr = false;
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
    
    cout << "The count is: " << count << " and the logFile is: " << logValue << endl;
    cout << "optErr: " << optErr << endl;

    return EXIT_SUCCESS;
}