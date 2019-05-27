

#include "User.h"

using namespace std;

User::User(string _email, string _username, string _password, int _age, int _user_id)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    user_id = _user_id;
    cout << OK << endl;
    money = 0;
}

string User::get_username()
{
    return username;
}


string User::get_password()
{
    return password;
};
    
void User::increase_money(int money_amount)
{
    money += money_amount;
}

int User::get_money()    
{
    return money;
}

void User::buy_film(int film_id, int _film_price)
{
    buyed_films_id.push_back(film_id);
    money -= _film_price;
    cout << OK << endl;
}


void User::show_notification()
{
    int index = 1;
    cout << Hashtak << Dot << Space << NotificationMessage << endl; 
    for(int i=notification.size()-1; i>-1; i--)
        notification[i].show_notifications(UnReaded, index);
}

void User::show_readed_notification()
{
    int index = 1;
    for(int i=notification.size()-1; i>-1; i--)
        notification[i].show_notifications(Readed, index);
}

void User::add_following(int _following_id)
{
    followers_id.push_back(_following_id);
    cout << OK << endl;
}


int User::get_user_id()
{
    return user_id;
}


string User::get_email()
{
    return email;
}

void User::add_notification(int _publisher_id, string _publisher_name, int _user_id, string _username, int _film_id, string _film_name, string _type)
{
    notification.push_back(Notifications(_publisher_id, _publisher_name, _user_id, _username, _film_id, _film_name, _type));
}

vector<int> User::check_buyed_films(vector<int> _film_ids)
{
    vector<int> common_ids;
    for (vector<int>::iterator i = _film_ids.begin(); i != _film_ids.end(); ++i)
    {
        if (find(buyed_films_id.begin(), buyed_films_id.end(), *i) != buyed_films_id.end())
        {
            common_ids.push_back(*i);
        }
    }
    return common_ids;
}

vector<int> User::get_buyed_films_id()
{
    return buyed_films_id;
}