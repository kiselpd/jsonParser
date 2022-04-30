#include <iostream>
#include "parser.hpp"


int main()
{
    ParserJson parser;

    std::cout << std::endl << "Client" << std::endl;
    clientMessage mes1("text to client", "time to client", "cryptoWord to client");

    std::string answer1 = parser.parsJsonToClient(mes1);
    std::cout << answer1;

    clientMessage answer2 = parser.parsJsonFromClient(answer1);
    std::cout << answer2.text << ", " << answer2.time << ", " << answer2.cryptoWord << std::endl;


    std::cout << std::endl << "Server" << std::endl;
    serverMessage mes2("text to server", "time to server", 4, "login to server");

    std::string answer3 = parser.parsJsonToServer(mes2);
    std::cout << answer3;

    serverMessage answer4 = parser.parsJsonFromServer(answer3);
    std::cout << answer4.text << ", " << answer4.time << ", " << answer4.type << ", " << answer4.login << std::endl;

    return 0;
}