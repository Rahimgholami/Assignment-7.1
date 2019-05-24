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



class FileSystemInterface
{
public:
    FileSystemInterface(std::string _commands);
    std::vector<std::string> text_to_vec(std::string commands);
    static bool space(char c);
    static bool not_space(char c);
    std::vector<std::string> split(const std::string& input_command);
    void check_commence(std::string command_commerce);
    void assign_command(std::vector<std::string> input_command);
    void run_commands();
    void add_command(std::vector<std::string> input_command);


private:
    std::vector<std::string> current_command;
    std::vector<std::string> commands;
    std::vector<std::vector<std::string>> splitted_commands;
    CommandHandler command_handler;
};

#endif
