#pragma once

#include <string>

struct clientMessage
{
public:
    std::string text;
    std::string time;
    std::string cryptoWord;

    clientMessage();
    clientMessage(std::string text, std::string time, std::string cryptoWord);
};

struct serverMessage
{
public:
    std::string text;
    std::string time;
    std::string login;
    size_t type;

    serverMessage();
    serverMessage(std::string text, std::string time, size_t type, std::string login);
};

class ParserJson
{
public:
    std::string parsJsonToClient(clientMessage message);
    std::string parsJsonToServer(serverMessage message);

    clientMessage parsJsonFromClient(std::string jsonString);
    serverMessage parsJsonFromServer(std::string jsonString);
};