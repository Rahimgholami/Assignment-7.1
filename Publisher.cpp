#include "Publisher.h"


using namespace std;

Publisher::Publisher(string _email, string _username, string _password, int _age, int _publisher_id)
:User(_email, _username, _password, _age, _publisher_id)
{
    publisher_id = _publisher_id;
}

void Publisher::add_film(int _film_id)
{
    published_films_id.push_back(_film_id);
}

void Publisher::show_followers()
{
    cout << ListOfFollowers << endl;
    cout << Hashtak << Dot << Space << USERID << Vertical 
        << UserUsername << Vertical << UserEmail << endl;
        for(int i=0; i<followers_id.size(); i++)
        {
            cout << (i+1) << Dot << Space << followers_id[i] << Vertical
                << followers_username[i] << Vertical << followers_email[i] << endl;
        }
}

void Publisher::get_money(vector<Film> _films)
{
    for(int i=0; i<published_films_id.size(); i++)
        increase_money(_films[published_films_id[i]].get_film_money());
    cout << OK << endl;
}

void Publisher::add_follower(int _follower_id, string _user_name, string _email)
{
    followers_id.push_back(_follower_id);
    followers_username.push_back(_user_name);
    followers_email.push_back(_email);
}

void Publisher::is_film_published(int _film_id)
{
    int check = 0;
    for(int i=0; i<published_films_id.size(); i++)
    {
        if(published_films_id[i] == _film_id)
            check = 1;
    }
    if(check == 0)
        throw PremissionDenied();
}

int Publisher::get_followers_size()
{
    return followers_id.size();
}

int Publisher::get_follower_id(int _index)
{
    return followers_id[_index];
}

void Publisher::search_in_films(int _film_id)
{
    int check = 0;
    for(int i=0; i<published_films_id.size(); i++)
    {
        if(published_films_id[i] == _film_id)
            check = 1;
    }
    if(check == 0)
        throw PremissionDenied();
}

vector<int> Publisher::get_published_films_id()
{
    return published_films_id;
}


