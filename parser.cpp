#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>

#include "parser.hpp"

const std::string TEXT = "text";
const std::string TIME = "time";
const std::string CRYPTO_WORD = "cryptoWord";
const std::string LOGIN = "login";
const std::string TYPE = "type";
const std::string EMPTY_STR = "";


std::string ParserClientMessage::parsToJson(void* message) 
{
    boost::property_tree::ptree json;

    clientMessage* sendMessage = (clientMessage*)message;

    json.put(TEXT, sendMessage->text);
    json.put(TIME, sendMessage->time);
    json.put(CRYPTO_WORD, sendMessage->cryptoWord);

    if (json.empty())
        return EMPTY_STR;

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);

    return myJsonEncodedData.str();
}


void* ParserClientMessage::parsFromJson(std::string jsonString)
{
    try
    {
        std::stringstream jsonEncodedData(jsonString);
        boost::property_tree::ptree json;

        boost::property_tree::read_json(jsonEncodedData, json);

        clientMessage* getMessage = new clientMessage;

        getMessage->text = json.get<std::string>(TEXT, EMPTY_STR);
        getMessage->time = json.get<std::string>(TIME, EMPTY_STR);
        getMessage->cryptoWord = json.get<std::string>(CRYPTO_WORD, EMPTY_STR);
        return getMessage;
    }
    catch (std::exception const& error)
    {
        //std::cerr << error.what() << std::endl; - возможно потом где-то сохранять ошибки
        clientMessage* emptyMessage = new clientMessage;
        return emptyMessage;
    }
}


std::string ParserServerMessage::parsToJson(void* message) 
{
    boost::property_tree::ptree json;

    serverMessage* sendMessage = (serverMessage*)message;

    json.put(TEXT, sendMessage->text);
    json.put(TIME, sendMessage->time);
    json.put(LOGIN, sendMessage->login);
    json.put(TYPE, sendMessage->type);

    if (json.empty())
        return EMPTY_STR;

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);

    return myJsonEncodedData.str();
}


void* ParserServerMessage::parsFromJson(std::string jsonString) 
{
    try
    {
        std::stringstream jsonEncodedData(jsonString);
        boost::property_tree::ptree json;

        boost::property_tree::read_json(jsonEncodedData, json);

        serverMessage* getMessage = new serverMessage;

        getMessage->text = json.get<std::string>(TEXT, EMPTY_STR);
        getMessage->time = json.get<std::string>(TIME, EMPTY_STR);
        getMessage->login = json.get<std::string>(LOGIN, EMPTY_STR);
        getMessage->type = json.get<size_t>(TYPE, 0);

        return getMessage;
    }
    catch (std::exception const& error)
    {
        //std::cerr << error.what() << std::endl; - возможно потом где-то сохранять ошибки
        serverMessage* emptyMessage = new serverMessage;
        return emptyMessage;
    }
}
