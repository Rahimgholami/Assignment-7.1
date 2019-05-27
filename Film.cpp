#include "Film.h"


using namespace std;

Film::Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director, int _film_id, int _publisher_id)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
    director = _director;
    status = Available;
    film_id = _film_id;
    film_inbox_money = Low;
    publisher_id = _publisher_id;
    rate = 0;
}

void Film::add_film_inbox_money()
{
    if(rate < LowInterval)
        film_inbox_money += price*rate*WeakFilm;
    else if((rate >= LowInterval) && (rate < HighInterval))
        film_inbox_money += price*rate*MediumFilm;
    else if((rate > HighInterval))
        film_inbox_money += price*rate*StrongFilm;
}

int Film::get_publisher_id()
{
    return publisher_id;
}

int Film::get_film_money()
{
    int inbox_money = film_inbox_money;
    film_inbox_money = 0;
    return inbox_money;
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

void Film::calc_avg()
{
    for(int i=0; i<rates.size(); i++)
        rate += rates[i];
    if(rates.size() != 0)
        rate = rate / rates.size();
    else 
        rate = 0;
    cout << OK << endl;
}

void Film::rate_film(int _rate_in, int user_id)
{
    int check = 0;
    for(int i=0; i<rated_user_id.size(); i++)
    {
        if(rated_user_id[i] == user_id)
        {
            rates[i] = _rate_in;
            check = 1;
        }
    }
    if(check == 0)
    {
        rates.push_back(_rate_in);
        rated_user_id.push_back(user_id);
    }
    calc_avg();
}

Film Film::get_film()
{
    return Film(name, year, length, price, summary, director,film_id,publisher_id);
}

void Film::comment_film(string content, int _user_id)
{
    comments.push_back(Comment(content, _user_id));
    cout << OK << endl;
}

int Film::get_comment_user_id(int _comment_id)
{
    return comments[_comment_id-1].get_user_id();
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
    cout << OK << endl;
}

string Film::film_status()
{
    return status;
}

void Film::set_film_name(string _name)
{
    name = _name;
}

void Film::edit_film(string _name, int _year, int _length, string _summary, string _director)
{

    name = (_name != EmptyString) ?_name:name;
    year = (_year != EmptyInt) ? _year:year;
    length = (_length != EmptyInt) ? _length:length;
    summary = (_summary != EmptyString) ? _summary:summary;
    director = (_director != EmptyString) ? _director:director;
    cout << OK << endl;
}

void Film::show_comment_replies(int _comment_id)
{
    vector<string> replies = comments[_comment_id].return_reply_comments();
    for(int i=0; i<replies.size(); i++)
        cout << _comment_id << Dot << replies[i] << endl;
}

void Film::show_search_film_details(int _index)
{
    cout << (_index+1) << Dot << film_id << Vertical << length << Vertical << price
         << Vertical << rate << Vertical << year << Vertical << director << endl;
}

void Film::show_film_detail_search(int &index)
{
    if(status != Deleted)
    {
       cout << index << Dot << Space << film_id << Vertical << name << Vertical << length
       << Vertical << price <<  Vertical << rate << Vertical << year << Vertical << director << endl;
        index++;
    }
}
void Film::show_film_characteristic()
{
    cout << DetailsOfFilm << Space << name << endl;
    cout << IdShow << EqualSpace << film_id << endl;
    cout << DirectorShow << EqualSpace << director << endl;
    cout << LengthShow << EqualSpace << length << endl;
    cout << YearShow << EqualSpace << year << endl;
    cout << SummaryShow << EqualSpace << summary << endl;
    cout << RateShow << EqualSpace << rate << endl;
    cout << PriceShow << EqualSpace << price << endl << endl;
    cout << CommentsShow << endl;
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
    if(status == Deleted)
        throw NotFound();
    show_film_characteristic();
    show_comments_reply();
    cout << endl;
    cout << RecommendationFilm << endl;
    cout << Hashtak << Dot << Space << FilmIdShow << Vertical << FilmNameShow << Vertical 
        << FilmLenghtShow << Vertical << FilmDirector << endl;
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
