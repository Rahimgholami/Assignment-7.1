#include "CommandHandler.h"
#include <regex>

using namespace std;
CommandHandler::CommandHandler()
{
}

bool CommandHandler::is_email_valid(const std::string& email)
{
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(email, pattern);
}

void CommandHandler::check_signup_command_size()
{
    int command_size = current_command.size();
    if((command_size > 13) || (command_size < 11))
        throw BadRequest();
}

int CommandHandler::find_element_in_vec(string search_element, int priority)
{
    vector<string>::iterator itr = find(current_command.begin(), current_command.end(), search_element);
    if (itr != current_command.cend())
	    return distance(current_command.begin(), itr);
	else 
    {
        if(priority == 1)
		    throw BadRequest();
        else
            return 0;
	}
}


void CommandHandler::check_signup_command()
{
    check_signup_command_size();
    if(current_command[2] == "?")
    {
        cerr << "OK" << endl;
    }
    else
        throw BadRequest();
}

void CommandHandler::process_command()
{
    string commence = current_command[0];
    string main_command = current_command[1];
    if(commence == POST)
    {
        if(main_command == SignUp)
            check_signup_command();
    }
}


void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
    process_command();
}


User CommandHandler::get_user(int _user_id)
{
    return users[_user_id-1];
}

Publisher CommandHandler::get_publisher(int _publisher_id)
{
    return publishers[_publisher_id-1];
}
