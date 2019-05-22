#include "Publisher.h"


using namespace std;

Publisher(std::string _email, std::string _username, std::string _password, int _age, int _publisher_id)
:User(_email, _username, _password, _age, _publisher_id)
{
    set_publisher_id();
}
    void add_film(string _film_name, int _film_year, int _film_length, int _film_price, string _film_summary, string _film_director);
    void delete_film(int _film_id);
    void edit_film(int _film_id, string _film_name, ,int _film_year, int _film_length, string _film_summary, string _film_director);
    void list_followers();
    void get_money();
    void show_published_films(string _name, int _min_rate, int _price, int _max_year, string _director);
    void reply_comments(int _film_id, string _comment_id, string _content);
    void delete_comments(int _film_id, int _comment_id);
private:
    int publisher_id;
    std::vector<int> followers_id;
    std::vector<Film*> published_films;

    
    