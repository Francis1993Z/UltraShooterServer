#include "lobby.hpp"

using namespace std;
using namespace sf;



void Lobby::listenc()
{
    socket.setBlocking(false);
if (socket.bind(sf::Socket::AnyPort) != sf::Socket::Done)
{
    // erreur...
}
else
{
    cout<<"port : "<<socket.getLocalPort()<<endl;
}
   mutex.lock();
   while(listen)
    {
   mutex.unlock();
        sf::IpAddress sender;
unsigned short port;
sf::Packet packet;

if(socket.receive(packet, sender, port) == sf::Socket::Done)
{
      string l;
packet>>l;
Clients.push_back(sender);
std::cout << l << " : " << sender << " Port " << port << std::endl;

}



    }


}

void Lobby::open()
{
    mutex.lock();
    Run=true;
    listen=true;
    mutex.unlock();
run();
}

void Lobby::run()
{

    int c;
    listenc_thread.launch();
while(Run)
{
    cout<<endl;
cout<<"Menu --> Server"<<endl;
cout<<"         |-->lobby"<<endl;
cout<<"1.list clients"<<endl;
cout<<"Other.Close the lobby"<<endl;
cin>>c;
switch (c)
{
case 1:
if(!Clients.empty())
{
        for (std::vector<sf::IpAddress>::iterator it=Clients.begin(); it!=Clients.end(); ++it )
        {
                cout<<"Client : " << *it<<endl;
               //cout<<Clients.size()<<endl;
        }
}
else
    {
 cout<<"No client connected"<<endl;
          cout<<endl;
}

    break;

default:
    cout<<"quit the lobby"<<endl;
        cout<<endl;
    close();
    break;
}
}

}

void Lobby::close()
{
        mutex.lock();
        listen=false;
          Run=false;
           mutex.unlock();
        cout<<"Waiting for the thread end.."<<endl;
        listenc_thread.wait();
        cout<<"Thread terminated."<<endl;

}
