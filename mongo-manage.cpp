#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv)
{
    if (!argv[1])
    {
        cout << "mongoDB Simple Manager is Working..." << endl;
        cout << "\"mongo-manage --help\" or \"-h\" for help" << endl;
        return 0;
    }
    else
    {
        string mongoStart = "brew services start mongodb-community@4.4";
        string mongoStop = "brew services stop mongodb-community@4.4";
        string mongoCheck = "ps aux | grep -v grep | grep mongod";
        string mongoLocal = "mongo";
        string mongoConnect = "mongo \"mongodb+srv://cluster0.yrhsq.mongodb.net/<dbname>\"";
        string arg = argv[1];
        if (arg == "--run" || arg == "-r")
        {
            system(mongoStart.c_str());
            return 0;
        }
        if (arg == "--stop" || arg == "-s")
        {
            system(mongoStop.c_str());
            return 0;
        }
        if (arg == "--check" || arg == "-c")
        {
            int checkVal = system(mongoCheck.c_str());
            if (checkVal == 256)
            {
                cout << "MongoDB is NOT running" << endl;
            }

            return 0;
        }
        if (arg == "--local" || arg == "-l")
        {
            system(mongoLocal.c_str());
            return 0;
        }
        if (arg == "--connect" || arg == "-con")
        {
            string userCommand = argv[2];
            string passwordCommand = argv[4];
            if (userCommand == "-u" && passwordCommand == "-p")
            {
                string user = argv[3];
                string password = argv[5];
                string command = mongoConnect + " " + userCommand + " " + user + " " + passwordCommand + " " + password;
                cout << command << endl;
                system((command).c_str());
                return 0;
            }
            cout << argc << endl;
            // mongo "mongodb+srv://cluster0.yrhsq.mongodb.net/<dbname>" -u budgetDB -p WUGqWOYoYWH0sY9S
            return 0;
        }
        if (arg == "--help" || arg == "-h")
        {
            cout << "mongoDB Simple Manager is Working..." << endl;
            cout << "\"mongo-manage --run\" or \"-r\" to run MongoDB (i.e. the mongod process) as a macOS service, issue the following" << endl;
            cout << "\"mongo-manage --stop\" or \"-s\" to stop a mongod running as a macOS service, use the following command as needed" << endl;
            cout << "\"mongo-manage --check\" or \"-c\" to verify that MongoDB is running, search for mongod in your running processes\n"
                 << endl;
            cout << "\"mongo-manage --local\" or \"-l\" to login LOCAL (127.0.0.1) only if your MongoDB service is running" << endl;
            cout << "\"mongo-manage --connect\" or \"-con\" \n \t\"-u user -p password\" to login ONLINE" << endl;

            return 0;
        }
        else
        {
            cout << "mongoDB Simple Manager is Working..." << endl;
            cout << "\"mongo-manage --help\" or \"-h\" for help" << endl;
            return 0;
        }
    }
}
