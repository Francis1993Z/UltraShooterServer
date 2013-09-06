#include <iostream>
#include <cstdio>
#include <string>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "filelogger.hpp"
#include "lobby.hpp"

using namespace std;
using namespace sf;

int main()
{

    bool Run=true;

   // Create object
    flog::FileLogger myLog ("1", "log.txt");

    // Writing warnings or errors to file is very easy and C++ style
    myLog << flog::FileLogger::Type::WARNING << "Hey! ... This is a warning message!";
    myLog << flog::FileLogger::Type::ERROR << "WOW! Something really wrong is happening here!";
    myLog << "hello";

int choice=0;

Lobby lobby;

    while(Run)
    {
            cout<<endl;
    cout<<"Menu --> Server"<<endl;
    cout<<"1.Open lobby"<<endl;
    cout<<"Other.Close server"<<endl;
        cout<<endl;
    cin>>choice;
switch (choice)
{
case 1:
    cout<<"Server open the lobby"<<endl;
        cout<<endl;
    lobby.open();
    choice=0;
    break;

default:
    cout<<"exit"<<endl;
    Run=false;
    break;
}



    }

    return 0;
}
