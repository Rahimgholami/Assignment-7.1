#ifndef __FILM_H__
#define __FILM_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Exception.h"

class Film
{
public:
    Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director);
    void set_film_id(int film_id);
    std::string get_film_name();
    void rate_film(int _rate_in);
    Film get_film();
    void comment_film(std::string content);
    void comment_reply(int comment_id, std::string content, std::string status);
private:
    int rated_num;
    int rate;
    int film_id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string director;
    std::vector<std::string> comments;
    std::map<int,std::string> comments_replies;
};

#endif