#include "Film.h"


using namespace std;

Film::Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director, int _film_id)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
    director = _director;
    status = Available;
    film_id = _film_id;
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
    return Film(name, year, length, price, summary, director,film_id);
}

void Film::comment_film(string content)
{
    Comment cc(content);
    comments.push_back(cc);
}

void Film::reply_comment(int comment_id, string content, string _status)
{
    if(_status == Publisher_word)
    {
        if(comments.size() != 0)
            comments[comment_id-1].reply_comment_message(content);
        else
            throw BadRequest();
    }
    else
        throw PremissionDenied();
}

void Film::delete_film()
{
    status = Deleted; 
}

string Film::film_status()
{
    return status;
}

void Film::edit_film(string _name, int _year, int _length, string _summary, string _director)
{
    name = (_name != EmptyString) ?_name:name;
    year = (_year != EmptyInt) ? _year:year;
    length = (_length != EmptyInt) ? _length:length;
    summary = (_summary != EmptyString) ? _summary:summary;
    director = (_director != EmptyString) ? _director:director;
}


void Film::show_film_details()
{
    cout << DetailsOfFilm << name << endl;
    cout << IdShow << EqualSpace << film_id << endl;
    cout << DirectorShow << EqualSpace << director << endl;
    cout << LengthShow << EqualSpace << length << endl;
    cout << YearShow << EqualSpace << year << endl;
    cout << SummaryShow << EqualSpace << summary << endl;
    cout << RateShow << EqualSpace << rate << endl;
    cout << PriceShow << EqualSpace << price << endl;
    cout << CommentsShow << endl;
    for(int i=0; i<comments.size(); i++)
    {
       // cout << (i+1) << comments[i] << endl;
        cout << "Replies will be added!" << endl; 
    }
    cout << RecommendationFilm << endl;
    cout << "Best Films will be added!" << endl;
} 

void Film::delete_comment(int _comment_id)
{
  //  comments[_comment_id-1] = EmptyString;
}
