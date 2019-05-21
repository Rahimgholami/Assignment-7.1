#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;


vector<string> text_to_vec(string input_str)
{
    string file_name(input_str);
    vector<string> input_map;
    string line, item;
    ifstream file(file_name);
    while ( getline( file, line ) )
        input_map.push_back(line);
   file.close();
   return input_map;
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
    vector<vector<string>> out;
    vector<string> outt;
    vector<string> input_map = text_to_vec(string(argv[1]));
    for(int i=0; i<input_map.size(); i++)
    {
        outt = split(input_map[i]);
        for(int j=0; j<outt.size();j++)
        cout << outt[j] <<endl;
    }
        //out.push_back(split(input_map[i]));
   /* for(int i=0; i<out.size();i++)
        cerr << out[i] << endl;*/
    return 0;
}
