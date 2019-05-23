/*
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

  
    cout << "Enter the command!" << endl;
    string input;
    getline(cin,input);
    vector<string> out = split(input);
    for(int i=0;i<out.size();i++)
      cout << out[i] << endl;





    string inputt = string(argv[1]);
    vector<string> input = text_to_vec(inputt);

    for(int j=0; j<input.size(); j++)
    {
      vector<string> test_string = split(input[j]);
    for(int i = 0; i< test_string.size(); i++)
        cout << test_string[i] << endl;
    }
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

}*/


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

int main()
{
	std::vector<char> v = { 'd','f','a','e','i','a'};
	char key = 'a';

	std::vector<char>::iterator itr = std::find(v.begin(), v.end(), key);

	if (itr != v.cend()) {
		std::cout << "Element present at index " << 
					std::distance(v.begin(), itr) << endl;
	}
	else {
		std::cout << "Element not found";
	}
  if(typeid(key) == typeid(char))
  cout << typeid(key).name() << endl;

	return 0;
}*/



/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;
                                                                                

class Date {
public:
    Date(int d, int m, int y);
    void set_date(int d, int m, int y);
    void print_date();
    void inc_one_day();
    bool equals(Date d);

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
private:
    int day;
    int month;
    int year;
};
                                                                                
Date::Date(int d, int m, int y)
{
    set_date(d, m, y);
}
                                                                                
bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int days_of_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::inc_one_day()
{
    day++;
    if (day > days_of_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::print_date()
{
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d) {
    return day == d.day && month == d.month && year == d.year;
}

Date str_to_date(string s) {
    //TODO: Handle formatting errors
    int slash_pos = s.find('/');
    int d = atoi(s.substr(0, slash_pos).c_str());
    s = s.substr(slash_pos + 1);
    slash_pos = s.find('/');
    int m = atoi(s.substr(0, slash_pos).c_str());
    int y = atoi(s.substr(slash_pos + 1).c_str());

    return Date(d, m, y);
}

class Person {
public:
    Person(string n, int d, int m, int y);
    Date get_bdate(int id) { return bdate[id]; }
    string get_name() { return name; }
private:
    string name;
    vector<Date> bdate; 
};

Person::Person(string n, int d, int m, int y)
    : bdate.push_back(Date(d, m, y))
{
    if (n == "")
        abort();
    name = n;
}

int main()
{
    vector<Person> vp;
    vp.push_back(Person("gholam", 2, 7, 1370));
    vp.push_back(Person("ghamar", 3, 12, 1368));
    vp.push_back(Person("alaleh", 12, 2, 1360));

    cout << "Today? ";
    string today_str;
    cin >> today_str;
    Date today = str_to_date(today_str);
    int id = 0;
    for (int i = 0; i < vp.size(); i++)
        if (vp[i].get_bdate(id).equals(today))
            cout << "Happy Birth Day " << vp[i].get_name() << "!\n";
}*/


/*

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Sec
{
public:
    Sec(int _id, string _name)
    {
        id = _id;
        name = _name;
    }
    string get_sec_name(){return name;}
    void print()
    {
        cout << name << endl;
    }
private:
    int id;
    string name;
};

class Round {
public:
    Round(int _randome)
    {
        sec_vec.push_back(Sec(1,"Tehran"));
        randome = _randome;
    };
    void set_sec(int _id, string _name)
    {
        sec_vec.push_back(Sec(_id,_name));
    }
    Sec get_sec(int id){return sec_vec[id];};
private:
    vector<Sec> sec_vec;
    int randome;
};

int main()
{
  Round r(5);
  r.set_sec(2,"Rahim");
  r.set_sec(3,"Ebrahim");
  r.set_sec(4,"Iran");

  r.get_sec(1).print();
  return 0;
}*/


/*
#include <iostream>
#include <fstream>
//#include <conio.h>
#include <string>
using namespace std;

class User {

public:
    User(string _username, string _password)
    {
        username = _username;
        password = _password;
    }
    string get_name(){return username;};
    void change_name()
    {
        username = get_name() + "ed";
    }
private:
	string username;
	string password;
};

int main() {
	
	User u("Rahim","Tehran");

    cout << u.get_name() << endl;
    u.change_name();
    cout << u.get_name() << endl;


	//getch();
}
*/

/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int a,b;
    a = 1;
    b = 10;
    a = (b==0) ? (b-1):a;
    cout << a << endl;
    return 0;
}*/


#include <iostream>
#include <string>
#include <regex>

using namespace std;

bool is_email_valid(const std::string& email)
{
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   return std::regex_match(email, pattern);
}

int main()
{
    std::string email1;// = "text.example@randomcom";
    cin >> email1;
    std::cout << email1 << " : " << (is_email_valid(email1) ?
      "valid" : "invalid") << std::endl;
}