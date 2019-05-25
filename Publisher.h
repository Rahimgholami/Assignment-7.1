#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__

#include "User.h"

class Publisher : public User
{
public:
    Publisher(std::string _email, std::string _username, std::string _password, int _age, int _publisher_id);
    void add_film(int _film_id);
    void delete_film(int _film_id);
    void edit_films(Film _film, int _film_id, std::string _film_name, int _film_year, int _film_length, std::string _film_summary, std::string _film_director);
    void list_followers();
    void get_money();
    void show_published_films(std::string _name, int _min_rate, int _price, int _max_year, std::string _director);
    void reply_comments(int _film_id, std::string _comment_id, std::string _content);
    void delete_comments(int _film_id, int _comment_id);
private:
    int publisher_id;
    std::vector<int> followers_id;
    std::vector<int> published_films_id;
};

#endif