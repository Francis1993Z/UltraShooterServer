#ifndef LOBBY_HPP
#define LOBBY_HPP

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Lobby
    {

                    bool listen, Run;
        sf::UdpSocket socket;
sf::Mutex mutex;
        sf::Thread listenc_thread;
        sf::Thread game_thread;
        std::vector<sf::IpAddress> Clients;
                void run();
                void listenc();



                public:
            Lobby() : listenc_thread(&Lobby::listenc, this), listen(true), Run(true) {};

            void open();
            void close();



    };

#endif // LOBBY_HPP
