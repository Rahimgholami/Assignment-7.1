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
#include "Exception.h"



class FileSystemInterface
{
public:
    FileSystemInterface(std::string _commands);
    std::vector<std::string> text_to_vec(std::string commands);
    static bool space(char c);
    static bool not_space(char c);
    std::vector<std::string> split(const std::string& input_command);
    void check_commence(std::string command_commerce);
    void run_commands();
    void assign_command(std::vector<std::string> input_command);
    void find_post_money_funtions();
    void find_post_functions(std::string main_command);
    void find_put_functions(std::string main_command);
    void find_get_films_functions();
    void find_get_notificaion_functions();
    void find_get_functions(std::string main_command);
    void find_delete_functions(std::string main_command);
    void process_command();
private:
    std::vector<std::string> current_command;
    std::vector<std::string> commands;
    std::vector<std::vector<std::string>> splitted_commands;
    CommandHandler command_handler;
};

#endif
