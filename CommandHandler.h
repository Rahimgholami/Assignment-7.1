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
#include "Define.h"
#include "Publisher.h"

class FileSystemInterface
{
public:
    void add_command(std::vector<std::string> input_command);
    void process_command();
    void signup(std::string _email, std::string _username, int _age, std::string _password);
    void login(std::string _username, std::string _password);
    //void get_command(std::string input_command);
private:
    vector<string> current_command;
    vector<User*> users;
    vector<Publisher*> publishers;
    string user_role;
};


#endif
