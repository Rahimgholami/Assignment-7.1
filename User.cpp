

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

void User::show_purchased_films(std::string name,int price,int min_year, int max_year, std::string director)
{
    for(int i=0; i<buyed_films_id.size(); i++)
        cerr << "It will completed till vector<film> completed" << endl;
}
void User::show_notification()
{
    for(int i=0; i<notification.size(); i++)
        notification[i].show_notification(UnReaded);
}

void User::show_readed_notification()
{
      for(int i=0; i<notification.size(); i++)
        notification[i].show_notification(Readed);
}

void User::add_following(int _following_id)
{
    followers_id.push_back(_following_id);
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

string User::get_email()
{
    return email;
}

void User::add_notification(int _publisher_id, string _publisher_name, int _user_id, string _username, int _film_id, string _film_name, string _type)
{
    notification.push_back(Notifications(_publisher_id, _publisher_name, _user_id, _username, _film_id, _film_name, _type));
}
