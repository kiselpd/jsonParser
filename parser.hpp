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

template<typename T>
class ParserJson
{
public:
    virtual std::string parsToJson(T sendMessage) = 0;
    virtual T parsFromJson(std::string jsonString) = 0;

    virtual ~ParserJson();
};

template<typename T>
class ParserClientMessage : public ParserJson<T>
{
public:
    std::string parsToJson(T sendMessage) override;
    T parsFromJson(std::string jsonString) override;

    ~ParserClientMessage();
};

template<typename T>
class ParserServerMessage : public ParserJson<T>
{
public:
    std::string parsToJson(T sendMessage) override;
    T parsFromJson(std::string jsonString) override;

    ~ParserServerMessage();
};