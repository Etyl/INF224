#include <iostream>
#include <sstream>
#include <algorithm>
#include <regex>
using namespace std;

#include "./class/Video.h"
#include "./class/Photo.h"
#include "./class/Group.h"
#include "./class/Film.h"
#include "./class/Manager.h"
#include "./tcpserver/tcpserver.h"

using MultimediaPtr = std::shared_ptr<Multimedia>;
typedef std::shared_ptr<Multimedia> MultimediaPtr;

const int PORT = 3489;

int main(int argc, const char *argv[])
{
    
    Manager * manager = new Manager();
    manager->createPhoto("photo1", "photo1.jpg", 100, 100);
    manager->createPhoto("photo2", "photo2.jpg", 200, 200);
    manager->createVideo("video1", "video1.mp4", 10);
    manager->createVideo("video2", "video2.mp4", 20);

    // create the TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response)
    {
        // the request sent by the client to the server
        // std::cout << "request: " << request << std::endl;

        response = "";
        stringstream res_stream = stringstream();

        std::istringstream iss(request); // Create an istringstream to parse the request string
        std::string parsed = "";
        
        if (getline(iss, parsed, ' ') && parsed == "display") {
            response = "Multimedia found : ( ";
            if (getline(iss, parsed, ' ')) {
                manager->findMultimedia(parsed, res_stream);
                response += res_stream.str();
                
                std::regex newlines_re("\n+");
                response = std::regex_replace(response, newlines_re, " | ");
                response = response.substr(0, response.size()-2);

                response += ")";

            }
        }
        

        // return false would close the connecytion with the client
        return true; 
    });

    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

    return 0;
}
