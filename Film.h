#ifndef __FILM_H__
#define __FILM_H__

#include <vector>
#include <string>

class Film
{
public:
    Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director);
    void set_film_id(int film_id);
private:
    int film_id;
    std::string name;
    int year;
    int length;
    int price;
    std::string summary;
    std::string directory;
};

#endif