#include "CommandHandler.h"
#include <regex>

using namespace std;
CommandHandler::CommandHandler()
{
}
/*

void CommandHandler::signup(string _email, string _username, int _age, string _password, string _status)
{
    int _user_id = users.size()+publishers.size()+1;
    if(_status == "user")
        users.push_back(User(_email, _username, _password, _age, _user_id));
    else
        publishers.push_back(Publisher(_email, _username, _password, _age, _user_id));   
}
*/

/*
void CommandHandler::signup(int _current)
{  
    current_user_id = _current;
}*/

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
/*
int CommandHandler::find_element_in_vec(vector<string> input_command, string search_element, int priority)
{
    vector<string>::iterator itr = find(input_command.begin(), input_command.end(), search_element);
    if (itr != input_command.cend())
	    return distance(input_command.begin(), itr);
	else 
    {
        if(priority == 1)
		    throw BadRequest();
        else
            return;
	}
}*/


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
      /*  signup(current_command[find_element_in_vec(Email, 1)+1], current_command[find_element_in_vec(UserName, 1)+1],
              current_command[find_element_in_vec(PassWord, 1)+1], current_command[find_element_in_vec(Age, 1)+1],
               current_command[find_element_in_vec(Publisher_word, 0)+1]);*/
           // signup("rahimgholami1998@gmail.com", "Rahim", 21, "Tehran", "user");
           cerr << "Not OK!" << endl;
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
            //signup();
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
    return publishers[_publisher_id-1]; //some errors
}
/*
void CommandHandler::login(string _username, string _password)
{
    for(int i=0; i<users.size(); i++)
    {
        vector<User>::iterator it = find((get_user(i).get_username()).begin(), (get_user(i).get_username()).end(), _username);
        if (it != ((users.get_user[i])->get_username).cend())
        {
            if((users.get_user[distance(current_command.begin(), it)])->get_password == _password)
                current_user_id = distance(current_command.begin(), it);
            else
                throw BadRequest();
        }
        else
            throw BadRequest();
    }
}
*/
