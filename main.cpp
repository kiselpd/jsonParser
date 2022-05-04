#include <iostream>
#include "parser.hpp"

int main()
{
    
    clientMessage mesToClient;

    mesToClient.text = "text for client";
    mesToClient.time = "00.20";
    mesToClient.cryptoWord = "fheughskefs";
    
    ParserJson<clientMessage> *parser = new ParserClientMessage<clientMessage>;
    
    std::string strToClient = parser->parsToJson(mesToClient);
    
    std::cout << strToClient;

    clientMessage mesFromClient = parser->parsFromJson(strToClient);
    std::cout << mesFromClient.text << " " << mesFromClient.time << " " << mesFromClient.cryptoWord << std::endl;

    delete parser;

    serverMessage mesToServer;

    mesToServer.text = "text for server";
    mesToServer.time = "00.20";
    mesToServer.type = 2;
    mesToServer.login = "k03iselev";

    ParserJson<serverMessage>* parser1 = new ParserServerMessage<serverMessage>;

    std::string strToServer = parser1->parsToJson(mesToServer);

    std::cout << strToServer;

    serverMessage mesFromServer = parser1->parsFromJson(strToServer);
    std::cout << mesFromServer.text << " " << mesFromServer.time << " " << mesFromServer.type << " " << mesFromServer.login << std::endl;

    delete parser1;
    return 0;
}