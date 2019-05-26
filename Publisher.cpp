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

void Publisher::delete_film(int _film_id)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::edit_films(Film _film, int _film_id, string _film_name, int _film_year, int _film_length, string _film_summary, string _film_director)
{
    int check = 0;
    for(int i=0; i<published_films_id.size(); i++)
    {
        if(_film_id == published_films_id[i])
        {
            _film.edit_film(_film_name,_film_year,_film_length,_film_summary,_film_director);
            check = 1;
        }
    }
    if(check == 0)
        throw PremissionDenied();
}

void Publisher::show_followers()
{
    cout << ListOfFollowers << endl;
    cout << Hashtak << Dot << Space << USERID << Vertical 
        << UserUsername << Vertical << UserEmail << endl;
        for(int i=0; i<followers_id.size(); i++)
        {
            cout << i << Dot << Space << followers_id[i] << Vertical
                << followers_username[i] << Vertical << followers_email[i] << endl;
        }
}


void Publisher::get_money(vector<Film> _films)
{
    for(int i=0; i<published_films_id.size(); i++)
        increase_money(_films[published_films_id[i]].get_film_money());
    cout << OK << endl;
}

void Publisher::show_published_films(string _name, int _min_rate, int _price, int _max_year, string _director)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::reply_comments(Film _film, string _comment_id, string _content)
{
    cerr << "It will be completed!" << endl;
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

