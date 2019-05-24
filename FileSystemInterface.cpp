#include "FileSystemInterface.h"


using namespace std;


vector<string> FileSystemInterface::text_to_vec(string commands)
{
    string file_name(commands);
    vector<string> input_commands;
    string line, item;
    ifstream file(file_name);
    while (getline(file,line))
        input_commands.push_back(line);
   file.close();
   return input_commands;
}    
    
bool FileSystemInterface::space(char c)
{
  return isspace(c);
}

bool FileSystemInterface::not_space(char c)
{
  return !isspace(c);
}

vector<string> FileSystemInterface::split(const string& input_command)
{
  typedef string::const_iterator iter;
  vector<string> splitted_command;
  iter i = input_command.begin();
  while (i != input_command.end()) 
  {
    i = find_if(i, input_command.end(), not_space);
    iter j = find_if(i, input_command.end(), space);
    if (i != input_command.end())
      splitted_command.push_back(string(i, j));
    i = j;
  }
  return splitted_command;
}

void FileSystemInterface::check_commence(string command_commerce)
{
  vector<string> commerce_commands {PUT, POST, GET, DELETE};
  if ((std::find(commerce_commands.begin(), commerce_commands.end(), command_commerce) != commerce_commands.end()) != 1)
    throw BadRequest();
}

void FileSystemInterface::assign_command(vector<string> input_command)
{
  command_handler.add_command(input_command);
}

void FileSystemInterface::find_post_money_funtions()
{
  third_command_member = current_command[3];
  if(third_command_member == "?")
    commandhandler.increase_money_user(current_command);
  else
    commandhandler.increase_money_publisher(current_command);
}

void FileSystemInterface::find_post_funcitons(string main_command)
{
  if(main_command == SignUp)
    commandhandler.signup(current_command);
  else if(main_command == Login)
    commandhandler.login(current_command);
  else if(main_command == Films)
    commandhandler.add_film_publisher(current_command);
  else if(main_command == Money)
    find_post_money_functions();
  else if(main_command == Replies)
    commandhandler.reply_comment_publisher(current_command);
  else if(main_command == Followers)
    commandhandler.add_follower_user(current_command);
  else if(main_command == Buy)
    commandhandler.buy_film_user(current_command);
  else if(main_command == Rate)
    commandhandler.rate_film_user(current_command);
  else if(main_command == Comment)
    commandhandler.comment_user(current_command);
  else
    throw BadRequest();
}

void FileSystemInterface::find_put_funcitons(string main_command)
{
  if(main_command == Films)
    commandhandler.edit_film_publisher(current_command);
  else
    throw BadRequest();
}


void FileSystemInterface::process_command()
{
  string commence = current_command[0];
  string main_command = current_command[1];
  if(commence == POST)
    find_post_functions(main_command);
  else if(commence == PUT)
    find_put_functions(main_command);
    

}

void FileSystemInterface::add_command(std::vector<std::string> input_command)
{
  current_command = input_command;
  process_command();
}


void FileSystemInterface::run_commands()
{
  for(int i=0; i<splitted_commands.size(); i++)
  {
    try
    {
      check_commence(splitted_commands[i][0]);
      assign_command(splitted_commands[i]);
    }catch(BadRequest bad_req)
    {
      std::cout << bad_req.what() << endl;
    }    
  }
}

FileSystemInterface::FileSystemInterface(string _commands)
{
  commands = text_to_vec(_commands);
  for(int i=0; i<commands.size(); i++)
  {
    splitted_commands.push_back(split(commands[i]));
    if(splitted_commands[splitted_commands.size()-1].size() == 0)
    {
      splitted_commands.pop_back();
    }
  }

  run_commands();
}
