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

string Film::get_film_director()
{
    return director;
}

string Film::get_film_summary()
{
    return summary;
}

int Film::get_film_length()
{
    return length;
}

int Film::get_film_year()
{
    return year;
}

int Film::get_film_rate()
{
    return rate;
}

int Film::get_film_price()
{
    return price;
}

int Film::get_film_id()
{
    return film_id;
}

string Film::get_film_status()
{
    return status;
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

void Film::show_comment_replies(int _comment_id)
{
    vector<string> replies = comments[_comment_id].return_reply_comments();
    for(int i=0; i<replies.size(); i++)
        cout << _comment_id << Dot << replies[i] << endl;
}

void Film::show_search_film_details(int _index)
{
    cout << (_index+1) << Dot << film_id << Vertical << length << Vertical << price << Vertical << rate << Vertical << year << Vertical << director << endl;
}

void Film::show_film_characteristic()
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
    cout << endl;
}

void Film::show_comments_reply()
{
    for(int i=0; i<comments.size(); i++)
    {
        cout << (i+1) << Dot << comments[i].get_comment() << endl;
        show_comment_replies(i); 
    }
}

void Film::show_film_details()
{
    show_film_characteristic();
    show_comments_reply();
    cout << endl;
    cout << RecommendationFilm << endl;
} 

void Film::delete_comment(int _comment_id)
{
    if(status == Available)
    {
        if(_comment_id <= comments.size())
        {
        comments[_comment_id-1].set_comment_status(Deleted);
        cout << OK << endl;
        }
        else
            throw NotFound();
    }
    else
        throw NotFound();
}
