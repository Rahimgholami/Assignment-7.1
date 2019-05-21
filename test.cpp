#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

using namespace std;


//eum command_commence { PUT, GET, POST , DELETE };

vector<string> text_to_vec(string commands)
{
    string file_name(commands);
    vector<string> input_commands;
    string line, item;
    ifstream file(file_name);
    while ( getline( file, line ) )
        input_commands.push_back(line);
   file.close();
   return input_commands;
}   

bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

vector<string> split(const string& input_command)
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

int main(int argc , char *argv[])
{
  vector<string> result = text_to_vec(argv[1]);

  /*
    cout << "Enter the command!" << endl;
    string input;
    getline(cin,input);
    vector<string> out = split(input);
    for(int i=0;i<out.size();i++)
      cout << out[i] << endl;
*/



/*
    string inputt = string(argv[1]);
    vector<string> input = text_to_vec(inputt);*/
/*
    for(int j=0; j<input.size(); j++)
    {
      vector<string> test_string = split(input[j]);
    for(int i = 0; i< test_string.size(); i++)
        cout << test_string[i] << endl;
    }*/
    //cout << command_commence << endl;
    return 0;
}


void signup(string command)
{
    size_t username_pos = command.find("username"); 
    size_t password_pos = command.find("password"); 
    if(username_pos > password_pos)
    {
        string username = command.substr(password_pos+8,command.size()-1);
        //string password = command.substr(password_pos+8, username_pos-1);
        cout << username << " & " << endl;//password << endl;
    }
    else
    {
        cout << username_pos << endl;
        string username = command.substr(username_pos,2);
        //string username = command.substr(username_pos+8,password_pos-username_pos-9);
        //string password = command.substr(username_pos+8, command.size()-username_pos-9);
        cout << username << endl; //password << endl;
    }

}