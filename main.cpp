#include <iostream>
#include <sstream>
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
    // cree le TCPServer
    auto *server = new TCPServer([&](std::string const &request, std::string &response)
    {
        // the request sent by the client to the server
        std::cout << "request: " << request << std::endl;
        std::istringstream iss(request); // Create an istringstream to parse the request string
        std::string parsed = "";
        if (getline(iss, parsed, ' ') && parsed == "display") {
            if (getline(iss, parsed, ' ')) {
                std::cout << "Displaying :" << parsed << std::endl;
            }
        }

        // the response that the server sends back to the client
        response = "RECEIVED: " + request;

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
