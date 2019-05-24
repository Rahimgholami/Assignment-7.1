#include "CommandHandler.h"
#include <regex>

using namespace std;
CommandHandler::CommandHandler()
{
    role = NotSets;
}



void CommandHandler::increase_money_user()
{
    cerr << "I";
}

void CommandHandler::increase_money_publisher()
{
cerr << "I";
}

void CommandHandler::login()
{
cerr << "I";
}

void CommandHandler::add_film_publisher()
{
    cerr << "I";
}

void CommandHandler::reply_comment_publisher()
{
cerr << "I";
}

void CommandHandler::add_follower_user()
{
cerr << "I";
}

void CommandHandler::buy_film_user()
{
cerr << "I";
}

void CommandHandler::rate_film_user()
{
cerr << "I";
}

void CommandHandler::comment_user()
{
cerr << "I";
}

void CommandHandler::edit_film_publisher()
{
cerr << "I";
}

void CommandHandler::show_film_details_user()
{
cerr << "I";
}

void CommandHandler::search_films_user()
{
cerr << "I";
}

void CommandHandler::show_readed_notifications_user()
{
cerr << "I";
}

void CommandHandler::show_notifications_user()
{
cerr << "I";
}

void CommandHandler::show_followers_list_publisher()
{
cerr << "I";
}

void CommandHandler::show_published_films_publisher()
{
cerr << "I";
}

void CommandHandler::show_buyed_films_user()
{
cerr << "I";
}

void CommandHandler::delete_film_publisher()
{
cerr << "I";
}

void CommandHandler::delete_comment_publisher( )
{
cerr << "I";
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

void CommandHandler::check_command_size(int min_size, int max_size)
{
    int command_size = current_command.size();
    if((command_size > max_size) || (command_size < min_size))
        throw BadRequest();
}

void CommandHandler::is_email_valid(const std::string& email)
{
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(std::regex_match(email, pattern) == 0)
        throw BadRequest();
}

void CommandHandler::check_signup_command()
{
    check_command_size(11,13);
    if(current_command[2] == "?")
    {
        cerr << "OK" << endl;
    }
    else
        throw BadRequest();
}

vector<int> CommandHandler::find_signup_key_indexes()
{
    check_signup_command();
    vector<int> indexes{find_element_in_vec(Email,1), find_element_in_vec(UserName,1), find_element_in_vec(PassWord,1), find_element_in_vec(Age,1)};
    is_email_valid(current_command[find_element_in_vec(Email,1)+1]);
    if(find_element_in_vec(Publisher_word,0) != 0)
    {
        if(current_command[find_element_in_vec(Publisher_word,0)+1] == "true")
            role = Publisher_word;
        else
            role = User_word;
    }
    return indexes;
}

void CommandHandler::signup()
{
    vector<int> key_indexes = find_signup_key_indexes();
    int id = users.size() + publishers.size() + 1;
    int age;
    try
    {
        age = stoi(current_command[key_indexes[3]+1]);
    }
    catch(invalid_argument er)
    {
        cerr << "Bad Request" << endl;
    }
    if(role == Publisher_word)
        publishers.push_back(Publisher(current_command[key_indexes[0]+1],current_command[key_indexes[1]+1],current_command[key_indexes[2]+1],age,id));
    else if(role == User_word)
        users.push_back(User(current_command[key_indexes[0]+1],current_command[key_indexes[1]+1],current_command[key_indexes[2]+1],age,id));
    else
        throw PremissionDenied();
}


/*
void CommandHandler::process_command()
{
    string commence = current_command[0];
    string main_command = current_command[1];
    if(commence == POST)
    {
        if(main_command == SignUp)
            check_signup_command();
    }
}*/


void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
}



User CommandHandler::get_user(int _user_id)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].get_user_id() == _user_id)
            return users[_user_id];
    }
    throw BadRequest();
}

Publisher CommandHandler::get_publisher(int _publisher_id)
{
    for(int i=0; i<publishers.size(); i++)
    {
        if(publishers[i].get_user_id() == _publisher_id)
            return publishers[_publisher_id];
    }
    throw BadRequest();
}
