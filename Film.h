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
    Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director, int _film_id);
    void set_film_id(int film_id);
    std::string get_film_name();
    void rate_film(int _rate_in);
    Film get_film();/*
    void comment_film(std::string content);
    void reply_comment(int comment_id, std::string content, std::string _status);*/
    void comment_film(std::string content);


    void reply_comment(int comment_id, std::string content, std::string _status);


    void delete_comment(int _comment_id);
    void delete_film();
    std::string film_status();
    void edit_film(std::string _name, int _year, int _length, std::string _summary, std::string _director);
    void show_film_details();
private:
    int rated_num;
    int rate;
    int film_id;
    std::string name;
    int year;
    int length;
    int price;
    std::string status;
    std::string summary;
    std::string director;
    std::vector<Comment> comments;
};

#endif