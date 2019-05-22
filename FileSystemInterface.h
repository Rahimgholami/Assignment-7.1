#ifndef __FILE_SYSTEM_INTERFACE_H__
#define __FILE_SYSTEM_INTERFACE_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include "Exception.h"
#include "CommandHandler.h"
#include "Define.h"


/*
constexpr char POST_SIGNUP[] = "POST signup";
constexpr char POST_LOGIN[] = "POST login";
constexpr char POST_FILM[] = "POST films";
constexpr char DELETE_FILMS[] = "DELETE films";
constexpr char PUT_FILMS[] = "PUT films";
constexpr char GET_FOLLOWERS[] = "GET followers";
constexpr char POST_MONEY[] = "POST money";
constexpr char GET_PUBLISHED[] = "GET published";
constexpr char POST_REPLIES[] = "POST replies";
constexpr char DELETE_COMMENTS[] = "DELETE comments";
constexpr char POST_FOLLOWERS[] = "POST followers";
constexpr char POST_MONEY_Q[] = "POST money";
constexpr char GET_FILMS[] = "GET films";
//constexpr char GET_FILMS_ID[] = "run_cores";//repeated
constexpr char POST_BUY[] = "POST buy";
constexpr char POST_RATE[] = "POST rate";
constexpr char POST_COMMENT[] = "POST comments";
constexpr char GET_PURCHACED[] = "GET purchased";
constexpr char GET_NOTIFICATION[] = "GET notification";
constexpr char GET_NOTIFICATION_READ[] = "GET notification read";*/


class FileSystemInterface
{
public:
    FileSystemInterface(std::string _commands);
    std::vector<std::string> text_to_vec(std::string commands);
    static bool space(char c);
    static bool not_space(char c);
    std::vector<std::string> split(const std::string& input_command);
    void assign_command(std::vector<std::string> input_command);
    void run_commands();
    void check_commence(std::string command_commerce);
    void check_commands(std::vector<std::vector<std::string>> input_commands);

private:
    std::vector<std::string> commands;
    std::vector<std::vector<std::string>> splitted_commands;
};

#endif
