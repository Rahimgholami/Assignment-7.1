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




#include<iostream>
#include<fstream>
//#include<cstring>
//for C strings
using namespace std;
int main()
{
    string
    command, //to choose what to do each time
    name, password, //the ones that are found in the file
    inName, inPassword, //the ones you are going to input from keyboard
    registerName, registerPassword; //also what you're going to input
    //and if you know C strings, just replace that with something like
    /*
    char
    command[9],
    name[31], password[31], //it could be any size, but like this you have got 30 characters at your
    //disposal, if you consider it to be enough
    inName[31], inPassword[31],
    registerName[31], registerPassword[31];
    */
    while (1)
    {
        cout<<"(register/exit/login)\n"
            <<"Command: ";
        getline(cin, command);
        //(for C strings)
        //cin.get(command, 9);
        //cin.get();
        if (command=="exit") //(for C strings) if (!strcmp(command, "exit"))
        {
            return 1;
        }
        if (command=="register") //(for C strings) if (!strcmp(command, "register"))
        {
            //open file for registration
            ofstream g("registration.txt"); //ofstream is the one for getting data from the file, 
            //and the file does not even have to exist. If it's ofstream, it'll take care of it for you.
            //but be warned that if there is a file called "registration.txt" in the name folder as the
            //.exe file, the contents will be deleted
            if (!g.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            cout<<"\n\n\n" //3 newlines
                <<"New Username: ";
            getline(cin, registerName); //input from keyboard will go into registerName
            cout<<"New Password: ";
            getline(cin, registerPassword); //input from keyboard will go into registerPassword
            g<<registerName; //this basically says "put whatever's to the right (registerName) into
            //g ("registration.txt")".
            g<<'\n'; //and now there will be a new line
            g<<registerPassword; //and now the password
            //all placed safely in the file that g opened
            g.close(); //always make sure you close the file, or else you might end up with some nasty
            //stuff in the memory
        }
        if (command=="login") //(for C strings) if (!strcmp(command, "login"))
        {
            //open file, and then put the name and password into the strings
            ifstream f("registration.txt"); //ifstream is the one for getting data from the file, and
            //let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) //if it's not open, then there is no such file with the given name inside
            //the folder (that is, in the folder where the .exe file is going to be)
            {
                cout<<"could not open file\n"; //just so that you know why it won't work if it doesn't
                return 0;
            }
            getline(f, name, '\n'); //reads the user name from file f (which is using "registration.txt")
            getline(f, password, '\n'); //reads the password from file f (which is using "registration.txt")
            //also, if you tell the file to get you that text up until '\n', that's when you know it reads
            //the whole line at most, and won't go any further
            //and that is done by the 3rd parameter
            f.close(); //you don't need it open now, since you have the name and password from the file

            //login
            while (1)
            {
                //you are going to input the name and password here
                cout<<"\n\n\n"
                    <<"Enter Username: ";
                getline(cin, inName);
                cout<<"Enter Password: ";
                getline(cin, inPassword);
                //or this, if you are working with C strings (second version of declaration)
                //cin.get(inName, 31);
                //cin.get();
                //cin.get(inPassword, 31);
                //cin.get();
                //and the "cin.get()" after each input line is necessary, or else[...]
                //no idea what's happening inside istream, but it's mandatory if you don't want your
                //input to get stuck or worse
                if (inName==name && inPassword==password)
                {
                    cout<<"Login Successful\n" //the '\n' is a character, so that's why I can add it 
                    //and it will automatically output a newline in console, alongside the string
                        <<"Welcome, "
                        <<inName;
                    break; //just exit the while loop if you've entered the valid account
                }
                cout<<"incorrect name or password\n"; //if you haven't entered the valid account,
                //then the while loop is not done yet. So that's why this output is without condition
            }
            //now do something about the account
        }
        cout<<"\n\n\n\n\n"; //give it 5 newlines
    }
    return 1;
}













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