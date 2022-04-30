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

clientMessage::clientMessage() {};
clientMessage::clientMessage(std::string text, std::string time, std::string cryptoWord) : text(text), time(time), cryptoWord(cryptoWord) {};

serverMessage::serverMessage() {};
serverMessage::serverMessage(std::string text, std::string time, size_t type, std::string login) : text(text), time(time), type(type), login(login) {};

std::string ParserJson::parsJsonToClient(clientMessage sendMessage)
{
    boost::property_tree::ptree json;

    json.put(TEXT, sendMessage.text);
    json.put(TIME, sendMessage.time);                                 
    json.put(CRYPTO_WORD, sendMessage.cryptoWord);

    if (json.empty())
        return EMPTY_STR;

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);           

    return myJsonEncodedData.str();
}

clientMessage ParserJson::parsJsonFromClient(std::string jsonString)
{
    try
    {
        std::stringstream jsonEncodedData(jsonString);
        boost::property_tree::ptree json;

        boost::property_tree::read_json(jsonEncodedData, json);                

        clientMessage getMessage;

        getMessage.text = json.get<std::string>(TEXT, EMPTY_STR);
        getMessage.time = json.get<std::string>(TIME, EMPTY_STR);
        getMessage.cryptoWord = json.get<std::string>(CRYPTO_WORD, EMPTY_STR);
        return getMessage;
    }
    catch (std::exception const& error)
    {
        //std::cerr << error.what() << std::endl; - возможно потом где-то сохранять ошибки
        clientMessage emptyMessage;
        return emptyMessage;
    }
}

std::string ParserJson::parsJsonToServer(serverMessage sendMessage)
{
    boost::property_tree::ptree json;

    json.put(TEXT, sendMessage.text);
    json.put(TIME, sendMessage.time);
    json.put(LOGIN, sendMessage.login);
    json.put(TYPE, sendMessage.type);

    if (json.empty())
        return EMPTY_STR;

    std::stringstream myJsonEncodedData;
    boost::property_tree::write_json(myJsonEncodedData, json);

    return myJsonEncodedData.str();
}

serverMessage ParserJson::parsJsonFromServer(std::string jsonString)
{
    try
    {
        std::stringstream jsonEncodedData(jsonString);
        boost::property_tree::ptree json;

        boost::property_tree::read_json(jsonEncodedData, json);                 

        serverMessage getMessage;

        getMessage.text = json.get<std::string>(TEXT, EMPTY_STR);
        getMessage.time = json.get<std::string>(TIME, EMPTY_STR);
        getMessage.login = json.get<std::string>(LOGIN, EMPTY_STR);
        getMessage.type = json.get<size_t>(TYPE, 0);

        return getMessage;
    }
    catch (std::exception const& error)
    {
        //std::cerr << error.what() << std::endl; - возможно потом где-то сохранять ошибки
        serverMessage emptyMessage;
        return emptyMessage;
    }
}

