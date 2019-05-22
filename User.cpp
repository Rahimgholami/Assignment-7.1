#include "User.h"


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

string User::get_passwoerd()
{
    return password;
}

void User::add_following(int following_id)
{
    followings_id.push_back(following_id);
}

void User::increase_money(int money_amount)
{
    money += money_amount;
}

void buy_film(int film_id)
{
    buyed_films.push_back(Film());
}
void rate_film(int film_id, string comment);
void show_purchased_films(string name,int price,int min_year, int max_year, string director);
void show_notification();
void show_readed_notification();




private:
    int user_id;
    vector<string> notification;
    vector<string> readed_notification;
    int money;
    vector<int> buyed_films_id;
    vector<int> following_id;
    vector<Film*> buyed_films;
};