#include "Film.h"

using namespace std;

Film::Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
    director = _director;
}

void Film::set_film_id(int _film_id)
{
    film_id = _film_id;
}

string Film::get_film_name()
{
    return name;
}

void Film::rate_film(int _rate_in)
{
    rate = (rate*rated_num + _rate_in)/(rated_num+1);
    rated_num++;
}

Film Film::get_film()
{
    return Film(name, year, length, price, summary, director);
}