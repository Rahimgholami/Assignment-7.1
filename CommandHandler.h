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

class CommandHandler
{
public:
    CommandHandler();
   // void signup(std::string _email, std::string _username, int _age, std::string _password, std::string _status);
       //void signup(int);
    static bool is_email_valid(const std::string& email);
    void check_signup_command_size();
    int find_element_in_vec(std::string search_element, int priority);
    void check_signup_command();
    void add_command(std::vector<std::string> input_command);
    void process_command();
    //void login(std::string _username, std::string _password);
    User get_user(int _user_id);
    Publisher get_publisher(int _publisher_id);
private:
    std::vector<std::string> current_command;
    std::vector<User> users;
    std::vector<Publisher> publishers;
    std::string user_role;
    int current_user_id;
};


#endif
