/*
#ifndef __USER_H__
#define __USER_H__


//#include "Film.h"

class User
{
public:
 // User(std::string _email, std::string _username, std::string _password, int _age, int _user_id);
    //std::string get_username(int _id);
    void show();
    std::string get_name();
    std::string get_password();//{return password;}; 
    //std::string get_password();
   // void add_following(int _following_id);
    void increase_money(int money_amount);
    //void show_username();
    void buy_film(int film_id);
    void rate_film(int film_id, std::string comment);
    void show_purchased_films(std::string name,int price,int min_year, int max_year, std::string director);
    void show_notification();
    void show_readed_notification();
    void add_following(int _following_id);


private:
    std::string email;
    std::string username;
    std::string password;
    int age;
    std::vector<std::string> notification;
    std::vector<std::string> readed_notification;
    int money;
    std::vector<int> followings_id;
    std::vector<int> buyed_films_id;
    //std::vector<Film> buyed_films;
};

#endif

*/


#ifndef __USER_H__
#define __USER_H__



#include "U.h"

using namespace std;

    U::U(string _username, string _password)
    {
        username = _username;
        password = _password;
    }
    string U::get_name()
    {
        return username;
    }
    void U::change_name()
    {
        username = get_name() + "ed";
    }


#endif