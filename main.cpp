#include <iostream>
#include "parser.hpp"

int main()
{
    message mesToClient;

    mesToClient.text = "text for client";
    mesToClient.time = "00.20";
    mesToClient.cryptoWord = "fheughskefs";

    ParserJson* parser = new ParserClientMessage;

    std::string strToClient = parser->parsToJson(mesToClient);

    std::cout << "Json to client:" << std::endl << strToClient;
    
    message mesFromClient = parser->parsFromJson(strToClient);

    std::cout << "String to client:" << std::endl << mesFromClient.text << " " << mesFromClient.time << " " << mesFromClient.cryptoWord << std::endl;;

    return 0;
}