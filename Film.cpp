#include "Film.h"


Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director)
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

