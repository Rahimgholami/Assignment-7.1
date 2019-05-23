

/*
#include "User.h"

#include <iostream>

using namespace std;

User::User(string _email, string _username, string _password, int _age, int _user_id)
{
    age = _age;
    password = _password;
    username = _username;
    email = _email;
    user_id = _user_id;
}

string User::get_username()
{
    return username;
}

void User::show_username()
{
    cout << username << endl;
}

void User::show()
{
    cout << "HI" << endl;
}
string User::get_name(){return username;};

string User::get_password()
{
    return password;
}

void User::add_following(int _following_id)
{
   // followings_id.push_back(_following_id);
       followings_id.push_back(_following_id);
}


void User::add_following(int _following_id)
{
    followings_id.push_back(_following_id);
}

void User::increase_money(int money_amount)
{
    money += money_amount;
}

void User::buy_film(int film_id)
{
    buyed_films_id.push_back(film_id);
}
void rate_film(int film_id, string comment);
void show_purchased_films(string name,int price,int min_year, int max_year, string director);
void show_notification();
void show_readed_notification();
*/



#include "User.h"

using namespace std;

    Usere::Usere(string _username, string _password)
    {
        username = _username;
        password = _password;
    }
    string Usere::get_name()
    {
        return username;
    }
    void Usere::change_name()
    {
        username = get_name() + "ed";
    }
