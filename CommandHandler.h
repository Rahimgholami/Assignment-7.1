#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "Exception.h"


class FileSystemInterface
{
public:
    void add_command(std::vector<std::string> input_command);
    void process_command();
    //void get_command(std::string input_command);
private:
    vector<string> current_command;
};


#endif
