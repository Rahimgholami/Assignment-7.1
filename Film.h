#ifndef __FILM_H__
#define __FILM_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Exception.h"
#include "Define.h"
#include "Comment.h"

class Film
{
public:
    Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director, int _film_id, int _publisher_id);
    void add_film_inbox_money();
    int get_publisher_id();

    int get_film_money();
    void set_film_id(int film_id);
    std::string get_film_name();
    std::string get_film_director();
    std::string get_film_summary();
    int get_film_id();
    int get_film_length();
    int get_film_year();
    int get_film_rate();
    int get_film_price();
    std::string get_film_status();

    
    void rate_film(int _rate_in);
    Film get_film();
    int get_comment_user_id(int _comment_id);
    /*
    
    void comment_film(std::string content);
    void reply_comment(int comment_id, std::string content, std::string _status);*/
    void comment_film(std::string content, int _user_id);


    void reply_comment(int comment_id, std::string content, std::string _status);


    void delete_comment(int _comment_id);
    
    void delete_film();
    std::string film_status();
    void edit_film(std::string _name, int _year, int _length, std::string _summary, std::string _director);
    void show_comment_replies(int _comment_id);
    void show_film_characteristic();
    void show_comments_reply();
    void show_search_film_details(int _index);
    void show_film_details();
    void show_film_detail_search(int &index);
    void set_film_name(std::string _name);
    
private:
    int rated_num;
    int rate;
    int film_id;
    std::string name;
    int year;
    int length;
    int price;
    int film_inbox_money;
    int publisher_id;
    std::string status;
    std::string summary;
    std::string director;
    std::vector<Comment> comments;
};

#endif