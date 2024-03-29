#include "CommandHandler.h"
#include <regex>

using namespace std;

CommandHandler::CommandHandler()
{
    role = NotSets;
}

void CommandHandler::logout_user()
{
    if(role != NotSets) 
    {
        role = NotSets;
        admin_status = Absent;
        cout << OK << endl;
    }
    else
        throw BadRequest();
}

int CommandHandler::find_element_in_vec(string search_element, int priority)
{
    vector<string>::iterator itr = find(current_command.begin(), current_command.end(), search_element);
    if (itr != current_command.cend())
	    return distance(current_command.begin(), itr);
	else 
    {
        if(priority == High)
		    throw BadRequest();
        else
            return 0;
	}
}

void CommandHandler::check_command_size(int min_size, int max_size)
{
    int command_size = current_command.size();
    if((command_size > max_size) || (command_size < min_size))
        throw BadRequest();
}

void CommandHandler::is_email_valid(const std::string& email)
{
   const std::regex pattern
      ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if(std::regex_match(email, pattern) == 0)
        throw BadRequest();
}

void CommandHandler::check_QuestionMark_command()
{
    if(current_command[2] == QuestionMark){}
    else
        throw BadRequest();
}

vector<int> CommandHandler::find_signup_key_indexes()
{
    check_command_size(11,13);
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(Email,High), find_element_in_vec(UserName,High), find_element_in_vec(PassWord,High), find_element_in_vec(Age,High)};
    is_email_valid(current_command[find_element_in_vec(Email,High)+1]);
    if(find_element_in_vec(Publisher_word,Low) != 0)
    {
        if(current_command[find_element_in_vec(Publisher_word,Low)+1] == True)
            role = Publisher_word;
        else
            role = User_word;
    }
    else
        role = User_word;
    return indexes;
}

void CommandHandler::check_uniqueness(vector<int> key_indexes, int age)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].get_username() == current_command[key_indexes[1]+1])
            throw BadRequest();
    }
    for(int i=0; i<publishers.size(); i++)
    {
        if(publishers[i].get_username() == current_command[key_indexes[1]+1])
            throw BadRequest();
    }
}

void CommandHandler::add_user_publisher_to_vector(vector<int> key_indexes, int age)
{
    check_uniqueness(key_indexes, age);
    if(role == Publisher_word)
    {
        publishers.push_back(Publisher(current_command[key_indexes[0]+1],current_command[key_indexes[1]+1],current_command[key_indexes[2]+1],age,users.size()+publishers.size()+1));
        current_publisher_index = publishers.size()-1;
        current_publisher_id = users.size()+publishers.size();
    }
    else if(role == User_word)
    {
        users.push_back(User(current_command[key_indexes[0]+1],current_command[key_indexes[1]+1],current_command[key_indexes[2]+1],age,users.size()+publishers.size()+1));
        current_user_index = users.size()-1;
        current_user_id = users.size()+publishers.size();
    }
    else
        throw PremissionDenied();
}

int CommandHandler::convert_string_to_int(string input_string)
{
    int output_int;
    try
    {
        output_int = stoi(input_string);
        return output_int;
    }
    catch(invalid_argument er)
    {
        throw BadRequest();
    }
}

void CommandHandler::signup()
{
    if(role == NotSets)
    {
        vector<int> key_indexes = find_signup_key_indexes();
        int age = convert_string_to_int(current_command[key_indexes[3]+1]);
        add_user_publisher_to_vector(key_indexes,age);
    }
    else
        throw BadRequest();
}

void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
}

bool CommandHandler::user_search()
{
    int check = 0;
    for(int i=0; i<users.size(); i++)
    {
        if(current_command[find_element_in_vec(UserName,High)+1] == users[i].get_username())
        {
            if(current_command[find_element_in_vec(PassWord,High)+1] == users[i].get_password())
            {
                cout << OK << endl;
                role = User_word;
                current_user_index = i;
                current_user_id = users[i].get_user_id();
                check = 1;
            }
        }
    }
    return check;
}

bool CommandHandler::publisher_search()
{
    int check = 0;
    for(int i=0; i<publishers.size(); i++)
    {
        if(current_command[find_element_in_vec(UserName,1)+1] == publishers[i].get_username())
        {
            if(current_command[find_element_in_vec(PassWord,1)+1] == publishers[i].get_password())
            {
                cout << OK << endl;
                role = Publisher_word;
                current_publisher_index = i;
                current_publisher_id = publishers[i].get_user_id();
                check = 1;
            }
        }
    }
    return check;
}

int CommandHandler::convert_user_id_to_index(int _user_id)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].get_user_id() == _user_id)
            return i;
    }
    throw NotFound();
}

int CommandHandler::convert_publisher_id_to_index(int _publisher_id)
{
    for(int i=0; i<publishers.size(); i++)
    {
        if(publishers[i].get_user_id() == _publisher_id)
            return i;
    }
    throw NotFound();
}

void CommandHandler::login()
{
    if(role == NotSets)
    {
        check_QuestionMark_command();
        check_command_size(7,7);
        int check_user_search = user_search();
        int check_publisher_search = publisher_search();
        if((check_user_search == 0) && (check_publisher_search == 0))
            throw BadRequest();
    }
    else if((current_command[4] == Admin) && (current_command[6] == Admin))
        admin_status = Present;
    else
        throw BadRequest();
}

void CommandHandler::check_increase_money()
{
    if((current_command[2] != QuestionMark) || (current_command[3] != Amount))
        throw BadRequest();
}

int CommandHandler::convert_money_to_int()
{
    int money=0;
    try
    {
        money = convert_string_to_int(current_command[4]);
    }
    catch(invalid_argument er)
    {
        throw BadRequest();
    }
    return money;
}

void CommandHandler::increase_money_user()
{
    check_increase_money();
    check_command_size(5,5);
    if(role == User_word)
    {
        users[current_user_index].increase_money(convert_money_to_int());
        cout << OK << endl;
    }
    else if(role == Publisher_word)
    {
        publishers[current_publisher_index].increase_money(convert_money_to_int());
        cout << OK << endl;
    }
    else
        throw PremissionDenied();
}

void CommandHandler::increase_money_publisher()
{
    check_command_size(2,2);
    if(role == Publisher_word)
        publishers[current_publisher_index].get_money(films);
    else
        throw PremissionDenied();
}

vector<int> CommandHandler::find_add_film_publisher_key_indexes()
{
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(Name,High), find_element_in_vec(Year,High), find_element_in_vec(Length,High),
                         find_element_in_vec(Price,High), find_element_in_vec(Summary,High), find_element_in_vec(Director,High)};
    return indexes;
}

void CommandHandler::add_film_to_vector(vector<int> key_indexes)
{
    if(role == Publisher_word)
    {   
    films.push_back(Film(current_command[key_indexes[0]+1], convert_string_to_int(current_command[key_indexes[1]+1]),
                        convert_string_to_int(current_command[key_indexes[2]+1]),convert_string_to_int(current_command[key_indexes[3]+1]),
                        current_command[key_indexes[4]+1],current_command[key_indexes[5]+1],films.size()+1,publishers[current_publisher_index].get_user_id()));
    publishers[current_publisher_index].add_film(films.size());  
    cout << OK << endl;
    }
    else
        throw PremissionDenied();
}

void CommandHandler::send_notification_to_followers(string _type)
{
    for(int i=0; i<publishers[current_publisher_index].get_followers_size(); i++)
    {
        
        int id = publishers[current_publisher_index].get_follower_id(i);
        if(id == users[convert_user_id_to_index(id)].get_user_id())
        {
            users[convert_user_id_to_index(id)].add_notification(current_publisher_id, publishers[current_publisher_index].get_username(), 
                                                                EmptyInt, EmptyString, EmptyInt, EmptyString, _type);
        }
        else if(id == publishers[convert_publisher_id_to_index(id)].get_user_id())
        {
            publishers[convert_publisher_id_to_index(id)].add_notification(current_publisher_id, publishers[current_publisher_index].get_username(), 
                                                                EmptyInt, EmptyString, EmptyInt, EmptyString, _type);                                              
        }
    }
}

void CommandHandler::add_film_publisher()
{
    check_command_size(14,15);
    vector<int> indexes = find_add_film_publisher_key_indexes();
    add_film_to_vector(indexes);
    send_notification_to_followers(RegisterNotification);
}   


vector<int> CommandHandler::find_comment_user_key_indexes()
{
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(FilmId,High), find_element_in_vec(Content,High)};
    return indexes;
}

void CommandHandler::comment_user()
{
    check_command_size(7,7);
    vector<int> indexes = find_comment_user_key_indexes();
    int _film_id = convert_string_to_int(current_command[indexes[0]+1])-1;
    if(role == User_word)
    {
        publishers[convert_publisher_id_to_index(films[_film_id-1].get_publisher_id())].add_notification(EmptyInt, EmptyString, current_user_id, 
                                users[current_user_index].get_username(), _film_id+1, films[_film_id].get_film_name(), CommentNotification); 
        films[_film_id].comment_film(current_command[indexes[1]+1], current_user_id);
    }
    else if(role == Publisher_word)
    {
        publishers[convert_publisher_id_to_index(films[_film_id-1].get_publisher_id())].add_notification(EmptyInt, EmptyString, current_user_id, 
                                publishers[current_publisher_index].get_username(), _film_id+1, films[_film_id].get_film_name(), CommentNotification);
        films[_film_id].comment_film(current_command[indexes[1]+1], current_publisher_id);
    }
}

vector<int> CommandHandler::find_reply_comment_key_indexes()
{
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(FilmId,High), find_element_in_vec(CommentId,High), find_element_in_vec(Content,High)};
    return indexes;
}

void CommandHandler::send_notification_to_followers(int id)
{
    if(id == users[convert_user_id_to_index(id)].get_user_id())
            users[convert_user_id_to_index(id)].add_notification(current_publisher_id, publishers[current_publisher_index].get_username(), 
                                                                EmptyInt, EmptyString, EmptyInt, EmptyString, ReplyNotification);
    else if(id == publishers[convert_publisher_id_to_index(id)].get_user_id())
            publishers[convert_publisher_id_to_index(id)].add_notification(current_publisher_id, publishers[current_publisher_index].get_username(), 
                                                                EmptyInt, EmptyString, EmptyInt, EmptyString, ReplyNotification);        
}

void CommandHandler::reply_comment_publisher()
{
    check_command_size(9,9);
    vector<int> indexes = find_reply_comment_key_indexes();
    publishers[current_publisher_index].search_in_films(convert_string_to_int(current_command[indexes[0]+1]));
    int comment_id = convert_string_to_int(current_command[indexes[1]+1]);
    films[convert_string_to_int(current_command[indexes[0]+1])-1].reply_comment(comment_id, current_command[indexes[2]+1], role);
    send_notification_to_followers(films[convert_string_to_int(current_command[indexes[0]+1])-1].get_comment_user_id(comment_id));
}

void CommandHandler::add_follwer_details(int _following_id, int _follower_index)
{
    int check = 0;
    for(int i=0; i<publishers.size(); i++)
    {
        if(publishers[i].get_user_id() == _following_id)
        {
            publishers[i].add_follower(users[_follower_index].get_user_id(), users[_follower_index].get_username(), users[_follower_index].get_email());
            check = 1;
        }
    }
    if(check == 0)
        throw BadRequest();
}

void CommandHandler::add_following_user()
{
    int _following_id = convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]);
    string _username = users[current_user_index].get_username();
    string _username_p = publishers[current_publisher_index].get_username();
    check_QuestionMark_command();
    check_command_size(5,5);
    if(role == User_word)
    {
        users[current_user_index].add_following(_following_id);
        add_follwer_details(_following_id, current_user_index);
        publishers[convert_publisher_id_to_index(_following_id)].add_notification(EmptyInt, EmptyString, current_user_id, _username, EmptyInt, EmptyString, FollowNotification);
    }
    else if(role == Publisher_word)
    {
        publishers[current_publisher_index].add_following(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]));
        add_follwer_details(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]), current_user_index);
        publishers[convert_publisher_id_to_index(_following_id)].add_notification(EmptyInt, EmptyString, current_publisher_id, _username_p, EmptyInt, EmptyString, FollowNotification);
    }
    else
        throw PremissionDenied();
}

void CommandHandler::check_user_money_sufficency(int _film_price)
{
    if(_film_price > users[current_user_index].get_money_user())
        throw PremissionDenied();
}

void CommandHandler::check_buy_exceptions(int _film_id)
{
    check_user_money_sufficency(films[_film_id-1].get_film_price());
    check_QuestionMark_command();
    check_command_size(5,5);    
    if((_film_id > films.size()) || films[_film_id].get_film_status() == Deleted) 
        throw NotFound(); 
}

void CommandHandler::buy_film_user()
{
    int _film_id = convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]);
    check_buy_exceptions(_film_id);
    if(role == User_word)
    {
        users[current_user_index].buy_film(_film_id, films[_film_id-1].get_film_price());
        publishers[convert_publisher_id_to_index(films[_film_id-1].get_publisher_id())].add_notification(EmptyInt, EmptyString, current_user_id, 
                                users[current_user_index].get_username(), _film_id, films[_film_id-1].get_film_name(), BuyNotificatoin);
        films[_film_id-1].add_film_inbox_money();
    }
    else if(role == Publisher_word)
    {
        publishers[current_publisher_index].buy_film(_film_id, films[_film_id-1].get_film_price());
        publishers[convert_publisher_id_to_index(films[_film_id-1].get_publisher_id())].add_notification(EmptyInt, EmptyString, current_publisher_id, 
                                publishers[current_publisher_index].get_username(), _film_id, films[_film_id-1].get_film_name(), BuyNotificatoin);
        films[_film_id-1].add_film_inbox_money();
    }
    else
        throw PremissionDenied();
}

void CommandHandler::rate_films(int _film_id, int score)
{
    vector<int> buyed_films_id;
    if(role == User_word)
        buyed_films_id = users[current_user_index].get_buyed_films_id();
    if(role == Publisher_word)
        buyed_films_id = users[current_publisher_index].get_buyed_films_id();
    int check = 0;
    for(int i=0; i<buyed_films_id.size(); i++)
    {
        if(_film_id == buyed_films_id[i])
        {
            if(role == User_word)
                films[_film_id-1].rate_film(score, current_user_id);
            else if(role == Publisher_word)
                films[_film_id-1].rate_film(score, current_publisher_id);
            check = 1;
        }
    }
    if(check == 0)
        throw PremissionDenied();
}

void CommandHandler::rate_film_user()
{
    check_QuestionMark_command();
    check_command_size(7,7);  
    Film _film = films[convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1])-1];  
    int _film_id = convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]);
    int _score = convert_string_to_int(current_command[(find_element_in_vec(Score, High))+1]);
    rate_films(_film_id, _score);
    publishers[convert_publisher_id_to_index(films[_film_id-1].get_publisher_id())].add_notification(EmptyInt, EmptyString, current_user_id, 
                                users[current_user_index].get_username(), _film_id, films[_film_id-1].get_film_name(), RateNotification);    
    if((role != Publisher_word) && (role != User_word))
        throw PremissionDenied();
}

vector<int> CommandHandler::find_edit_film_key_indexes()
{
    check_command_size(5,15);
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(FilmId,High), find_element_in_vec(Name,Low), find_element_in_vec(Year,Low),
                         find_element_in_vec(Length,Low), find_element_in_vec(Summary,Low), find_element_in_vec(Director,Low)};
    return indexes;
}

void CommandHandler::edit_films(int _film_id, string _film_name, int _film_year, int _film_length, string _film_summary, string _film_director)
{
    vector<int> published_films_id = publishers[current_publisher_index].get_published_films_id();
    int check = 0;
    for(int i=0; i<published_films_id.size(); i++)
    {
        if(_film_id == published_films_id[i])
        {
            films[_film_id-1].edit_film(_film_name,_film_year,_film_length,_film_summary,_film_director);
            check = 1;
        }
    }
    if(check == 0)
        throw PremissionDenied();
}

void CommandHandler::edit_film_publisher()
{
    vector<int> indexes = find_edit_film_key_indexes();
    int film_id = convert_string_to_int(current_command[indexes[0]+1]);
    publishers[current_publisher_index].is_film_published(film_id);
    string name = (indexes[1] != 0) ? current_command[indexes[1]+1] : EmptyString;
    int year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int length = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    string summary = (indexes[4] != 0) ? current_command[indexes[4]+1] : EmptyString;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
    if(role == Publisher_word)
        edit_films(film_id,name,year,length,summary,director);
    else
        throw PremissionDenied();
}

vector<int> CommandHandler::inverse_vector(vector<int> input_vector)
{
    vector<int> sorted;
    for(int i=input_vector.size()-1; i > -1; i--)
    {
        sorted.push_back(input_vector[i]);
    }
    return sorted;
}

vector<int> CommandHandler::sort_films_rate(vector<int> sorted_films_id, vector<int> sorted_films_rate)
{
    int i, j, min, temp;
   for (i = 0; i < sorted_films_id.size()-1; i++) 
   {
       min = i;
      for (j = i + 1; j < sorted_films_id.size(); j++)
      {
            if(sorted_films_rate[j] <= sorted_films_rate[min])
                min = j;
      }
      temp = sorted_films_rate[i];
      sorted_films_rate[i] = sorted_films_rate[min];
      sorted_films_rate[min] = temp;
      temp = sorted_films_id[i];
      sorted_films_id[i] = sorted_films_id[min];
      sorted_films_id[min] = temp;
   }
   return inverse_vector(sorted_films_id);
}

bool CommandHandler::is_user_buy_both_films(int _first_film_id, int _second_film_id, int user_index, string role)
{
    vector<int> user_buyed_films;
    int check = 0;
    if(role == User_word)
        user_buyed_films = users[user_index].get_buyed_films_id();
    else if(role == Publisher_word)
        user_buyed_films = publishers[user_index].get_buyed_films_id();
    if(find(user_buyed_films.begin(), user_buyed_films.end(), _first_film_id+1) != user_buyed_films.end())
    {
        if(find(user_buyed_films.begin(), user_buyed_films.end(), _second_film_id+1) != user_buyed_films.end())
            check = 1;
    }
    return check;
}

void CommandHandler::add_matrix_elements(int _first_id, int _second_id, vector<vector<int>> &film_matrix)
{
    for(int k=0; k<users.size(); k++)
    {
        if(is_user_buy_both_films(_first_id, _second_id, k, User_word))
        {
            film_matrix[_first_id][_second_id]++;
            film_matrix[_second_id][_first_id]++;
        }
    }
    for(int k=0; k<publishers.size(); k++)
    {
        if(is_user_buy_both_films(_first_id, _second_id, k, Publisher_word))
        {
            film_matrix[_first_id][_second_id]++;
            film_matrix[_second_id][_first_id]++;
        }
    }
}

vector<int> CommandHandler::best_films_matrix(int n, int k)
{
    vector<vector<int>> vec2D(n, vector<int>(n, 0));
    vector<int> best_films;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            add_matrix_elements(i,j,vec2D);
    }
    return vec2D[k];
}

vector<int> CommandHandler::sort_best_films(vector<int> best_films)
{
    vector<int> sorted_films_rate;
    vector<int> sorted_films_id;
    for(int i=0; i<best_films.size(); i++)
    {   
        if(films[i].get_film_status() != Deleted)
        {
            sorted_films_id.push_back(i+1);
            sorted_films_rate.push_back(best_films[i]);
        }
    }
    sorted_films_id = sort_films_rate(sorted_films_id, sorted_films_rate);
    return sorted_films_id;
}


// vector<int> CommandHandler::find_best_films()
// {
//     vector<Film> sorted_films;
//     vector<int> sorted_films_rate;
//     vector<int> sorted_films_id;
//     for(int i=0; i<films.size(); i++)
//     {   
//         if(films[i].get_film_status() != Deleted)
//         {
//             sorted_films_id.push_back(i+1);
//             sorted_films_rate.push_back(films[i].get_film_rate());
//         }
//     }
//     sorted_films_id = sort_films_rate(sorted_films_id, sorted_films_rate);
//     return sorted_films_id;
// }

void CommandHandler::show_best_films(vector<int> _this_user_best_films)
{
    int n = NumberOfShownFilms;
    int min = (_this_user_best_films.size()< NumberOfShownFilms) ? _this_user_best_films.size() : NumberOfShownFilms;
    for(int i=0; i<min; i++)
        if(convert_string_to_int(current_command[4]) != _this_user_best_films[i])
            cout << (i+1) << Dot << Space << _this_user_best_films[i] << Vertical
            << films[_this_user_best_films[i]-1].get_film_name() << Vertical << films[_this_user_best_films[i]-1].get_film_length()
            << Vertical << films[_this_user_best_films[i]-1].get_film_director() << endl;
}

void CommandHandler::process_best_films(vector<int> _best_films_id)
{
    vector<int> buyed_films_id;
    vector<int> _this_user_best_films;
    if(role == User_word)
        buyed_films_id = users[current_user_index].get_buyed_films_id();
    else if(role == Publisher_word)
        buyed_films_id = publishers[current_publisher_index].get_buyed_films_id();
    for(int i=0; i<_best_films_id.size(); i++)
    {
        if (find(buyed_films_id.begin(), buyed_films_id.end(), _best_films_id[i]) != buyed_films_id.end()){}
        else
            _this_user_best_films.push_back(_best_films_id[i]);
    }
    show_best_films(_this_user_best_films);
}

void CommandHandler::show_film_details_user()
{
    check_command_size(5,5);
    check_QuestionMark_command();
    if(current_command[3] == FilmId)
    {
        if(convert_string_to_int(current_command[4]) <= films.size())
        {
            films[convert_string_to_int(current_command[4])-1].show_film_details();
            process_best_films(sort_best_films(best_films_matrix(films.size(), convert_string_to_int(current_command[4])-1)));
        }
        else
            throw NotFound();
    }
    else
        throw BadRequest();
}

vector<int> CommandHandler::find_search_key_indexes()
{
    vector<int> indexes{find_element_in_vec(Name,Low), find_element_in_vec(MinRate,Low),  find_element_in_vec(MinYear,Low),
                        find_element_in_vec(Price,Low), find_element_in_vec(MaxYear,Low), find_element_in_vec(Director,Low)};
    return indexes;
}

void CommandHandler::show_all_films_detail()
{
    for(int i=0; i<films.size(); i++)
        films[i].show_search_film_details(i);
}

void CommandHandler::delete_film_publisher()
{
    if(role != Publisher_word)
        throw PremissionDenied();
    check_command_size(5,5);
    check_QuestionMark_command();
    int _film_id = convert_string_to_int(current_command[find_element_in_vec(FilmId,High)+1]);
    publishers[current_publisher_index].is_film_published(_film_id);
    films[_film_id-1].delete_film();
}

void CommandHandler::delete_comment_publisher( )
{
    if(role != Publisher_word)
        throw PremissionDenied();
    check_command_size(7,7);
    check_QuestionMark_command();
    int _film_id = convert_string_to_int(current_command[find_element_in_vec(FilmId,High)+1]);
    int _comment_id = convert_string_to_int(current_command[find_element_in_vec(CommentId,High)+1]);
    publishers[current_publisher_index].is_film_published(_film_id);
    films[_film_id-1].delete_comment(_comment_id);
}

void CommandHandler::show_followers_list_publisher()
{
    check_command_size(2,2);
    if(role == Publisher_word)
        publishers[current_publisher_index].show_followers();
}

void CommandHandler::show_readed_notifications_user()
{
    if(role == Publisher_word)
        publishers[current_publisher_index].show_readed_notification();
    else if(role == User_word)
        users[current_user_index].show_notification();
}

void CommandHandler::show_notifications_user()
{
    if(role == Publisher_word)
        publishers[current_publisher_index].show_notification();
    else if(role == User_word)
        users[current_user_index].show_notification();
}

vector<int> CommandHandler::find_films_name(vector<int> input_ids, string _name)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<films.size(); i++)
    {
        if(films[i].get_film_name() == _name)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_films_min_rate(vector<int> input_ids, int _min_rate)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<input_ids.size(); i++)
    {
        if(films[input_ids[i]].get_film_rate() >= _min_rate)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_films_min_year(vector<int> input_ids, int _min_year)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<input_ids.size(); i++)
    {
        if(films[input_ids[i]].get_film_year() >= _min_year)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_films_max_year(vector<int> input_ids, int _max_year)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<input_ids.size(); i++)
    {
        if(films[input_ids[i]].get_film_year() <= _max_year)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_films_director(vector<int> input_ids, string _director)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<input_ids.size(); i++)
    {
        if(films[input_ids[i]].get_film_director() == _director)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_films_price(vector<int> input_ids, int _price)
{
    vector<int> ids;
    int check = 0;
    for(int i=0; i<input_ids.size(); i++)
    {
        if(films[input_ids[i]].get_film_price() == _price)
            ids.push_back(i);
        check = 1;
    }
    return (check == 1) ? ids: input_ids;
}

vector<int> CommandHandler::find_common_elements(vector<int> vec1, vector<int> vec2)
{
    vector<int> common_elements;
    for (vector<int>::iterator i = vec1.begin(); i != vec1.end(); ++i)
    {
        if (find(vec2.begin(), vec2.end(), *i) != vec2.end())
        {
            common_elements.push_back(*i);
        }
    }
    return common_elements;
}

vector<int> CommandHandler::filtered_vector(vector<int> vec1 , vector<int> vec2, vector<int> vec3, vector<int> vec4, vector<int> vec5, vector<int> vec6)
{
    if((vec1.size()!=0) && (vec2.size()!=0) && (vec3.size()!=0) && (vec4.size()!=0) && (vec5.size()!=0) && (vec6.size()!=0))
    {
        vector<int> common_element = find_common_elements(vec1, vec2);
        vector<int> common_element2 = find_common_elements(vec3, vec4);
        vector<int> common_element3 = find_common_elements(vec5, vec6);
        vector<int> common_element4 = find_common_elements(common_element, common_element2);
        return find_common_elements(common_element4, common_element3);
    }
    else
    {
        vector<int> ids;
        for(int i=0; i<films.size(); i++)
            ids.push_back(i);
        return ids;
    }
}

vector<int> CommandHandler::filter_search(string _name, int min_rate, int min_year, int max_year, string _director, int _price)
{
    vector<int> films_id, filtered_films_name, filtered_films_minrate, filtered_films_minyear, filtered_films_maxyear, filtered_films_director, filtered_films_price;
    for(int i=0; i<films.size(); i++)
        films_id.push_back(i);
    if(_name != EmptyString)
        filtered_films_name = find_films_name(films_id, _name);
    if(min_rate != EmptyInt)
        filtered_films_minrate = find_films_min_rate(films_id, min_rate);
    if(min_year != EmptyInt)
        filtered_films_minyear = find_films_min_year(films_id, min_year);
    if(max_year != EmptyInt)
        filtered_films_maxyear= find_films_max_year(films_id, max_year);
    if(_director != EmptyString)
        filtered_films_director = find_films_director(films_id, _director);
    if(_price != EmptyInt)
        filtered_films_price = find_films_price(films_id, _price);
    return filtered_vector(filtered_films_name, filtered_films_minrate, filtered_films_minyear, filtered_films_maxyear, filtered_films_director, filtered_films_price);
}

void CommandHandler::show_search(vector<int> ids)
{ 
    int k=1;
    if(ids.size() != 0)
    {
        for(int i=0; i<ids.size(); i++)
        {
            publishers[current_publisher_index].is_film_published(ids[i]);
            films[ids[i]-1].show_film_detail_search(k);
        }
    }   
    else
    {
        for(int i=0; i<films.size(); i++)
        {
            publishers[current_publisher_index].is_film_published(i);
            films[i].show_film_detail_search(k);
        }
    }
}


void CommandHandler::edit_search_films_features()
{
    check_command_size(3,15);
    check_QuestionMark_command();
    vector<int> indexes = find_search_key_indexes();
    string name = (indexes[0] != 0) ? current_command[indexes[0]+1] : EmptyString;
    int min_rate = (indexes[1] != 0) ? convert_string_to_int(current_command[indexes[1]+1]) : EmptyInt;
    int min_year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int price = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    int max_year = (indexes[4] != 0) ? convert_string_to_int(current_command[indexes[4]+1]) : EmptyInt;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
    vector<int> filtered_films_id = filter_search(name, min_rate, min_year, max_year, director, price);
    cout << Hashtak << Dot << Space <<  FilmIdShow << Vertical << FilmNameShow << Vertical << FilmLenghtShow << Vertical
        << FilmPriceShow << Vertical << FilmRateShow << Vertical << FilmProductionYear << Vertical << FilmDirector << endl; 
    show_search(filtered_films_id);
}

vector<int> CommandHandler::process_find_elements()
{
    check_command_size(2,15);
    check_QuestionMark_command();
    vector<int> indexes = find_search_key_indexes();
    string name = (indexes[0] != 0) ? current_command[indexes[0]+1] : EmptyString;
    int min_rate = (indexes[1] != 0) ? convert_string_to_int(current_command[indexes[1]+1]) : EmptyInt;
    int min_year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int price = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    int max_year = (indexes[4] != 0) ? convert_string_to_int(current_command[indexes[4]+1]) : EmptyInt;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
    return filter_search(name, min_rate, min_year, max_year, director, price);
}

void CommandHandler::show_published_films_publisher()
{
    if(process_find_elements().size() == films.size())
    {
            cout << Hashtak << Dot << Space <<  FilmIdShow << Vertical << FilmNameShow << Vertical << FilmLenghtShow << Vertical
        << FilmPriceShow << Vertical << FilmRateShow << Vertical << FilmProductionYear << Vertical << FilmDirector << endl; 
        show_search(publishers[current_publisher_index].get_published_films_id());
    }
    else
        show_search(process_find_elements());
}

void CommandHandler::show_search_user(vector<int> ids)
{ 
    int k=1;
    if(ids.size() != 0)
    {
        for(int i=0; i<ids.size(); i++)
            films[ids[i]].show_film_detail_search(k);
    }   
    else
    {
        for(int i=0; i<films.size(); i++)
            films[i].show_film_detail_search(k);
    }
}

void CommandHandler::search_films_user()
{
    vector<int> ids = process_find_elements();
    cout << Hashtak << Dot << Space <<  FilmIdShow << Vertical << FilmNameShow << Vertical << FilmLenghtShow << Vertical
        << FilmPriceShow << Vertical << FilmRateShow << Vertical << FilmProductionYear << Vertical << FilmDirector << endl;
    show_search_user(ids);
}

vector<int> CommandHandler::process_buy_elements()
{
    check_command_size(2,15);
    check_QuestionMark_command();
    vector<int> indexes = find_search_key_indexes();
    vector<int> films_id;
    string name = (indexes[0] != 0) ? current_command[indexes[0]+1] : EmptyString;
    int min_year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int price = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    int max_year = (indexes[4] != 0) ? convert_string_to_int(current_command[indexes[4]+1]) : EmptyInt;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
    return filter_search(name, EmptyInt, min_year, max_year, director, price);
}

vector<int> CommandHandler::check_user_films(vector<int> _film_ids)
{
    if(role == User_word)
        return users[current_user_index].check_buyed_films(_film_ids);
    else if(role == Publisher_word)
        return publishers[current_publisher_index].check_buyed_films(_film_ids);
    else
        throw PremissionDenied();
}

void CommandHandler::show_buyed_films_user()
{
    vector<int> ids = process_buy_elements();
    ids = check_user_films(ids);
    cout << Hashtak << Dot << Space <<  FilmIdShow << Vertical << FilmNameShow << Vertical << FilmLenghtShow << Vertical
        << FilmPriceShow << Vertical << FilmRateShow << Vertical << FilmProductionYear << Vertical << FilmDirector << endl; 
    int k = 1;
    for(int i=0; i<ids.size(); i++)
            films[ids[i]-1].show_film_detail_search(k);
}

int CommandHandler::get_whole_money()
{
    int money = 0;
    for(int i=0; i<users.size(); i++)
        money += users[i].get_money_user();
    for(int i=0; i<publishers.size(); i++)
        money += publishers[i].get_money_user();
    return money;
}

void CommandHandler::show_user_money()
{
    if(role == User_word)
        cout << users[current_user_index].get_money_user() << endl;
    else if(role == Publisher_word)
        cout << publishers[current_publisher_index].get_money_user() << endl;
    if(admin_status == Present)
        cout << get_whole_money();
    else
        throw BadRequest();
}