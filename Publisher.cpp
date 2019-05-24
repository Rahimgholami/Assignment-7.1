#include "Publisher.h"


using namespace std;

Publisher::Publisher(string _email, string _username, string _password, int _age, int _publisher_id)
:User(_email, _username, _password, _age, _publisher_id)
{
    publisher_id = _publisher_id;
}
void Publisher::add_film(int _film_id)
{
    cerr << "HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << endl;
   // published_films_id.push_back(_film_id);
    cerr << "D" << endl;
}

void Publisher::delete_film(int _film_id)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::edit_film(int _film_id, string _film_name, int _film_year, int _film_length, string _film_summary, string _film_director)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::list_followers()
{
    for(int i=0; i<followers_id.size(); i++)
        cout << followers_id[i] << endl;
}

void Publisher::get_money()
{
    cerr << "It will be completed!" << endl;
}

void Publisher::show_published_films(string _name, int _min_rate, int _price, int _max_year, string _director)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::reply_comments(int _film_id, string _comment_id, string _content)
{
    cerr << "It will be completed!" << endl;
}

void Publisher::delete_comments(int _film_id, int _comment_id)
{
    cerr << "It will be completed!" << endl;
}


    
    