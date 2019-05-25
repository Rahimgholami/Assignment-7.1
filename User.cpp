

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
};
    
void User::buy_film(int film_id)
{
    buyed_films_id.push_back(film_id);
}

void User::show_purchased_films(std::string name,int price,int min_year, int max_year, std::string director)
{
    for(int i=0; i<buyed_films_id.size(); i++)
        cerr << "It will completed till vector<film> completed" << endl;
}
void User::show_notification()
{
    for(int i=0; i<notification.size(); i++)
        cout << notification[i] << endl;
}

void User::show_readed_notification()
{
      for(int i=0; i<readed_notification.size(); i++)
        cout << readed_notification[i] << endl;
}

void User::add_follower(int _follower_id)
{
    followers_id.push_back(_follower_id);
}


int User::get_user_id()
{
    return user_id;
}

void User::rate_films(Film _film, int _film_id, int score)
{
    int check = 0;
    for(int i=0; i<buyed_films_id.size(); i++)
    {
        if(_film_id == buyed_films_id[i])
        {
            _film.rate_film(score);
            check = 1;
        }
    }
    if(check == 0)
        throw PremissionDenied();
}
    
void User::show_best_films(vector<Film> _best_films)
{
    vector<Film> _this_user_best_films;
    for(int i=0; i<_best_films.size(); i++)
    {
        if (find( buyed_films_id.begin(), buyed_films_id.end(), _best_films[i].get_film_id() ) != buyed_films_id.end()){}
        else
            _this_user_best_films.push_back(_best_films[i]);
    }
    int n = NumberOfShownFilms;
    if(_this_user_best_films.size() < NumberOfShownFilms)
        n = _this_user_best_films.size();
    for(int i=0; i<n; i++)
        cout << (i+1) << Dot << _this_user_best_films[i].get_film_id() << Vertical 
            << _this_user_best_films[i].get_film_name() << Vertical << _this_user_best_films[i].get_film_length() 
            << Vertical << _this_user_best_films[i].get_film_director() << endl;
}