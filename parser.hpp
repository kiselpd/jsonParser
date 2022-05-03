#pragma once

#include <string>

struct message
{
public:
    std::string text;
    std::string time;
    std::string cryptoWord;
    std::string login;
    size_t type;
};

class ParserJson
{
public:
    virtual std::string parsToJson(message sendMssage) = 0;
    virtual message parsFromJson(std::string jsonString) = 0;

};

class ParserClientMessage : public ParserJson
{
public:
    std::string parsToJson(message sendMessage) override;
    message parsFromJson(std::string jsonString) override;
};

class ParserServerMessage : public ParserJson
{
public:
    std::string parsToJson(message sendMessage) override;
    message parsFromJson(std::string jsonString) override;
};
