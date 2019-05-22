#include "CommandHandler.h"

using namespace std;

void CommandHandler::signup(string _email, string _username, int _age, string _password, int _status)
{
    int _user_id = users.size()+publishers.size()+1;
    if(_status = "user")
        users.push_back(new User(_email, _username, _password, _age, _user_id));
    else
        publishers.push_back(new publisher(_email, _username, _password, _age, _user_id));   
}

void CommandHandler::check_signup_command(vector<string> current_command)
{
    if(current_command[3] == "?")
    {
        
    }
    else
        throw BadRequest();
}

void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
}
    
void CommandHandler::process_command()
{
    string commence = current_command[0];
    string main_command = current_command[1];
    if(commence == POST)
    {
        if(main_command == SignUp)
            signup();
    }
}

void CommandHandler::login(string _username, string _password)
{
    vector<User*>::iterator it;
    it = find ((users->get_username).begin(), (users->get_username).end(), _username);
    if (it != (users->get_username).end())
    {
        if(users[it]->get_password == _password)
            current_user_id = it;
        else
            throw BadRequest();
    }
    else
        throw BadRequest();
}
    //void get_command(string input_command);
private:
    int current_user_id;
    vector<string> current_command;
    vector<User*> users;
    vector<Publisher*> publishers;
    string user_role;