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

void FileSystemInterface::find_post_money_funtions()
{
  if(current_command.size() == 2)
    command_handler.increase_money_publisher();
  else if(current_command[2] == QuestionMark)
  {
    command_handler.increase_money_user();
  }
  else
    throw BadRequest();
}

void FileSystemInterface::find_post_functions(string main_command)
{
  if(main_command == SignUp)
    command_handler.signup();
  else if(main_command == Login)
    command_handler.login();
  else if(main_command == Films)
    command_handler.add_film_publisher();
  else if(main_command == Money)
    find_post_money_funtions();
  else if(main_command == Replies)
    command_handler.reply_comment_publisher();
  else if(main_command == Followers)
    command_handler.add_following_user();
  else if(main_command == Buy)
    command_handler.buy_film_user();
  else if(main_command == Rate)
    command_handler.rate_film_user();
  else if(main_command == CommentString)
    command_handler.comment_user();
  else
    throw BadRequest();
}

void FileSystemInterface::find_put_functions(string main_command)
{
  if(main_command == Films)
    command_handler.edit_film_publisher();
  else
    throw BadRequest();
}

void FileSystemInterface::find_get_films_functions()
{
  if((current_command[2] == QuestionMark) && (current_command.size()>2))
  {
    if(current_command[3] == FilmId)
      command_handler.show_film_details_user();
    else
      command_handler.search_films_user();
  }
  else if(current_command.size() == 2)
  {
    command_handler.search_films_user();
  }
  else
    throw BadRequest();
}

void FileSystemInterface::find_get_notificaion_functions()
{
  if(current_command[2] == Read)
    command_handler.show_readed_notifications_user();
  else
    command_handler.show_notifications_user();
}

void FileSystemInterface::find_get_functions(string main_command)
{
  if(main_command == Followers)
    command_handler.show_followers_list_publisher();
  else if(main_command == Published)
    command_handler.show_published_films_publisher();
  else if(main_command == Films)
    find_get_films_functions();
  else if(main_command == Purchased)
    command_handler.show_buyed_films_user();
  else if(main_command == Notification)
    find_get_notificaion_functions();
  else
    throw BadRequest();
}

void FileSystemInterface::find_delete_functions(string main_command)
{
  if(main_command == Films)
    command_handler.delete_film_publisher();
  else if(main_command == Comments)
    command_handler.delete_comment_publisher();
  else
    throw BadRequest();
}

void FileSystemInterface::process_command()
{
  command_handler.add_command(current_command);
  string commence = current_command[0];
  string main_command = current_command[1];
  if(commence == POST)
    find_post_functions(main_command);
  else if(commence == PUT)
    find_put_functions(main_command);
  else if(commence == GET)
    find_get_functions(main_command);
  else if(commence == DELETE)
    find_delete_functions(main_command);
  else
    throw BadRequest();
}

void FileSystemInterface::assign_command(std::vector<std::string> input_command)
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
    }catch(NotFound not_found)
    {
      cout << not_found.what() << endl;
    }catch(PremissionDenied Pre_denied)
    {
      cout << Pre_denied.what() << endl;
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
