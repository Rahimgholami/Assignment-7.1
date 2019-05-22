#include "Publisher.h"


using namespace std;

Publisher::Publisher(string _email, string _username, string _password, int _age, int _publisher_id)
:User(_email, _username, _password, _age, _publisher_id)
{
    set_publisher_id();
}
void Publisher::add_film(string _film_name, int _film_year, int _film_length, int _film_price, string _film_summary, string _film_director)
{

}

void Publisher::delete_film(int _film_id)
{

}

void Publisher::edit_film(int _film_id, string _film_name, int _film_year, int _film_length, string _film_summary, string _film_director)
{
    
}

void Publisher::list_followers()
{

}

void Publisher::get_money()
{

}

void Publisher::show_published_films(string _name, int _min_rate, int _price, int _max_year, string _director)
{

}

void Publisher::reply_comments(int _film_id, string _comment_id, string _content)
{

}

void Publisher::delete_comments(int _film_id, int _comment_id)
{
    
}


    
    