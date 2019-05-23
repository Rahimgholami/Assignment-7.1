

#include "User.h"

using namespace std;

User::User(string _email, string _username, string _password, int _age, int _user_id)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    user_id = _user_id;
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
};
    
void User::buy_film(int film_id)
{
    buyed_films_id.push_back(film_id);
}/*
    void User::rate_films(int film_id, std::string comment)
    {
        for(int i=0; i<buyed_films_id.size(); i++)
            vector<int>::iterator itr = find(buyed_films_id.begin(), buyed_films_id.end(), film_id);
        if (itr != buyed_films_id.cend())
 
    };*/
    void User::show_purchased_films(std::string name,int price,int min_year, int max_year, std::string director){};
    void User::show_notification(){};
    void User::show_readed_notification(){};
    void User::add_following(int _following_id){};