#include <iostream>
#include "parser.hpp"

int main()
{
    
    clientMessage* mesToClient = new clientMessage;

    mesToClient->text = "text for client";
    mesToClient->time = "00.20";
    mesToClient->cryptoWord = "fheughskefs";
    
    ParserJson *parser = new ParserClientMessage;
    
    std::string strToClient = parser->parsToJson(mesToClient);
    
    std::cout << strToClient;
    
    clientMessage* mesFromClient = (clientMessage*)(parser->parsFromJson(strToClient));
    std::cout << mesFromClient->text << " " << mesFromClient->time << " " << mesFromClient->cryptoWord << std::endl;
    
    //delete parser;

    serverMessage* mesToServer = new serverMessage;

    mesToServer->text = "text for server";
    mesToServer->time = "00.20";
    mesToServer->type = 2;
    mesToServer->login = "k03iselev";

    ParserJson *parser1 = new ParserServerMessage;

    std::string strToServer = parser1->parsToJson(mesToServer);

    std::cout << strToServer;

    serverMessage* mesFromServer = (serverMessage*)(parser1->parsFromJson(strToServer));
    std::cout << mesFromServer->text << " " << mesFromServer->time << " " << mesFromServer->type << " " << mesFromServer->login << std::endl;

    //delete parser1;
    
    return 0;
}