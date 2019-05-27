#ifndef __PUBLISHER_H__
#define __PUBLISHER_H__

#include "User.h"

class Publisher : public User
{
public:
    Publisher(std::string _email, std::string _username, std::string _password, int _age, int _publisher_id);
    void add_film(int _film_id);
    void show_followers();
    void get_money(std::vector<Film> _films);
    void add_follower(int _follower_id, std::string _user_name, std::string _email);
    void is_film_published(int _film_id);
    int get_followers_size();
    int get_follower_id(int _index);
    void search_in_films(int _film_id);
    std::vector<int> get_published_films_id();
private:
    int publisher_id;
    std::vector<int> followers_id;
    std::vector<std::string> followers_username;
    std::vector<std::string> followers_email;
    std::vector<int> published_films_id;
};

#endif