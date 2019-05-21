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

void FileSystemInterface::check_commence(vector<vector<string>> input_commands)
{

}

void FileSystemInterface::check_commands(vector<vector<string>> input_commands)
{

}
/*
void FileSystemInterface::run_commands(vector<string> _input_commands)
{
  
}
*/

FileSystemInterface::FileSystemInterface(string _commands)
{
  vector<vector<string>> inn;
   commands = text_to_vec(_commands);
  for(int i=0; i<commands.size(); i++)
    {
      splitted_commands.push_back(split(commands[i]));
      for(int j=0; j<split(commands[i]).size();j++)
        cout << splitted_commands[i][j] <<endl;
    }
}
