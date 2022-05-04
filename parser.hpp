#pragma once
#include<iostream>
#include <string>

struct clientMessage
{
    std::string text;
    std::string time;
    std::string cryptoWord;
};

struct serverMessage
{
    std::string text;
    std::string time;
    std::string login;
    size_t type;
};

class ParserJson
{
public:
    virtual std::string parsToJson(void* message) = 0;
    virtual void* parsFromJson(std::string jsonString) = 0;
};

class ParserClientMessage : public ParserJson
{
public:
    std::string parsToJson(void* message) override;
    void* parsFromJson(std::string jsonString) override;
};

class ParserServerMessage : public ParserJson
{
public:
    std::string parsToJson(void* message) override;
    void* parsFromJson(std::string jsonString) override;
};
