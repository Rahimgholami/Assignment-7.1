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

void FileSystemInterface::check_commands(vector<vector<string>> input_commands)
{/*
  try
  {
    check_commence(input_commands);
  }catch(BadRequest bad_req)
  {
    std::cerr << bad_req.what() << endl;
  }*/
  cerr << "Will be deleted!!" << endl;
}

void FileSystemInterface::assign_command(vector<string> input_command)
{
  //if(input_command[1] == )
  add_command(input_command);
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
      cerr << "here" << endl;
    }
  }
  cerr << splitted_commands.size() << endl;
  run_commands();
}
