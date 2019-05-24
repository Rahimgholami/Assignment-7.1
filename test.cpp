#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*

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

vector<string> text_to_vec(string commands)
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
    


int main(int argc , char *argv[])
{
    vector<string> commands = text_to_vec(string(argv[1]));
    for(int i=0; i<commands.size(); i++)
    {
        vector<string> splitted = split(commands[i]); 
        for(int j=0; j< splitted.size(); j++)
            cout << typeid(splitted[j].name()) << endl;
    }
    vector<string> in;
    int i;
    string j;
    char k;
    cin >> i >> j >> k;
    in.push_back(i);
    in.push_back(j);
 //   in.push_back(k);
    return 0;
}*/
/*

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A
{
public:
  A(string _name, int _id)
  {
    name = _name;
    id = _id;
  }
  string get_name()
  {
    return name;
  }
private:
  string name;
  int id;
};

class B
{
public:
  B():tt("R",4)
  {
  }
  A set_A(string _name,int _id)
  {
    return A(_name,_id);
  }
  void add_A(string _name, int _id)
  {
    aa.push_back(A(_name,_id));
  }
  void show_names()
  {
    for(int i=0; i< aa.size(); i++)
      cout << aa[i].get_name() << endl;
  }
private:
  vector<A> aa;
  A tt;
};

class C
{
public:
  C()
  {
    B b;
    b.add_A("Rahim",1);
    b.add_A("Yahya", 2);
    b.show_names();
  }
};

int main()
{
  C c;
  return 0;
}*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  vector<string> input;

  for(int i=0; i<3; i++)
  {
    string ss;
    cin >> ss;
    input.push_back(ss);
  }
  for(int i=0; i<input.size(); i++)
    cout << typeid(input[i]).name() << input[i] << endl;
    try
    {
      int ca = stoi(input[1]);
      cout << ca;
      //cout << typeid(ca).name() << endl;
    }catch(invalid_argument er)
    {
      cout << "error!" << endl;
    }
}