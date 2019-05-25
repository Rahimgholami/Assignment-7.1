#include "CommandHandler.h"
#include <regex>

using namespace std;
CommandHandler::CommandHandler()
{
    role = NotSets;
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
        //cerr << "Bad Request" << endl;
        throw BadRequest();
    }
}

void CommandHandler::signup()
{
    vector<int> key_indexes = find_signup_key_indexes();
    int age = convert_string_to_int(current_command[key_indexes[3]+1]);
    add_user_publisher_to_vector(key_indexes,age);
}

void CommandHandler::add_command(vector<string> input_command)
{
    current_command = input_command;
}

/*

User CommandHandler::get_user(int _user_id)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].get_user_id() == _user_id)
            return users[_user_id];
    }
    throw BadRequest();
}

Publisher CommandHandler::get_publisher(int _publisher_id)
{
    for(int i=0; i<publishers.size(); i++)
    {
        if(publishers[i].get_user_id() == _publisher_id)
            return publishers[_publisher_id];
    }
    throw BadRequest();
}*/

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
                current_user_id = i;
                check = 1;
            }
        }
    }
    return check;
}

bool CommandHandler::publisher_search()
{
    int check = 0;
    for(int i=0; i<users.size(); i++)
    {
        if(current_command[find_element_in_vec(UserName,1)+1] == publishers[i].get_username())
        {
            if(current_command[find_element_in_vec(PassWord,1)+1] == publishers[i].get_password())
            {
                cout << OK << endl;
                role = Publisher_word;
                current_publisher_id = i;
                check = 1;
            }
        }
    }
    return check;
}

void CommandHandler::login()
{
    check_QuestionMark_command();
    int check_user_search = user_search();
    int check_publisher_search = publisher_search();
    if((check_user_search == 0) && (check_publisher_search))
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
        users[current_user_index].increase_money(convert_money_to_int());
    else if(role == Publisher_word)
        publishers[current_publisher_index].increase_money(convert_money_to_int());
    else
        throw PremissionDenied();
}

void CommandHandler::increase_money_publisher()
{
    check_command_size(2,2);
    publishers[current_publisher_index].get_money();
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
                        current_command[key_indexes[4]+1],current_command[key_indexes[5]+1],films.size()+1));
    publishers[current_publisher_index].add_film(films.size());  
    }
    else
        throw PremissionDenied();
}

void CommandHandler::add_film_publisher()
{
    check_command_size(15,15);
    vector<int> indexes = find_add_film_publisher_key_indexes();
    add_film_to_vector(indexes);
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
    films[convert_string_to_int(current_command[indexes[0]+1])-1].comment_film(current_command[indexes[1]+1]);
}


vector<int> CommandHandler::find_reply_comment_key_indexes()
{
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(FilmId,High), find_element_in_vec(CommentId,High), find_element_in_vec(Content,High)};
    return indexes;
}
void CommandHandler::reply_comment_publisher()
{
    check_command_size(9,9);
    vector<int> indexes = find_reply_comment_key_indexes();
    films[convert_string_to_int(current_command[indexes[0]+1])-1].reply_comment(convert_string_to_int(current_command[indexes[1]+1]), current_command[indexes[2]+1], role);
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
    check_QuestionMark_command();
    check_command_size(5,5);
    if(role == User_word)
    {
        users[current_user_index].add_following(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]));
        add_follwer_details(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]), current_user_index);
    }
    else if(role == Publisher_word)
    {
        publishers[current_publisher_index].add_following(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]));
        add_follwer_details(convert_string_to_int(current_command[(find_element_in_vec(UserId,High))+1]), current_user_index);
    }
    else
        throw PremissionDenied();
}



void CommandHandler::buy_film_user()
{
    check_QuestionMark_command();
    check_command_size(5,5);    
    if((convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]) > films.size()) || 
            films[convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1])].get_film_status() == Deleted) 
        throw NotFound(); 
    if(role == User_word)
        users[current_user_index].buy_film(convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]));
    else if(role == Publisher_word)
        publishers[current_publisher_index].buy_film(convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1])); 
    else
        throw PremissionDenied();
}

void CommandHandler::rate_film_user()
{
    check_QuestionMark_command();
    check_command_size(7,7);    
    if(role == User_word)
        users[current_user_index].rate_films(films[convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1])],
                                            convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]),
                                             convert_string_to_int(current_command[(find_element_in_vec(Score, High))+1]));

    else if(role == Publisher_word)
        publishers[current_publisher_index].rate_films(films[convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1])-1],
                                            convert_string_to_int(current_command[(find_element_in_vec(FilmId, High))+1]),
                                             convert_string_to_int(current_command[(find_element_in_vec(Score, High))+1]));
    else
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


void CommandHandler::edit_film_publisher()
{
    vector<int> indexes = find_edit_film_key_indexes();
    int film_id = convert_string_to_int(current_command[indexes[0]+1]);
    string name = (indexes[1] != 0) ? current_command[indexes[1]+1] : EmptyString;
    int year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int length = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    string summary = (indexes[4] != 0) ? current_command[indexes[4]+1] : EmptyString;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
    if(role == Publisher_word)
        publishers[current_publisher_index].edit_films(films[film_id-1],film_id,name,year,length,summary,director);
    else
        throw PremissionDenied();
}

vector<Film> CommandHandler::best_films()
{
    vector<Film> sorted_films;
    vector<int> sorted_films_id;
    for(int i=0; i<films.size(); i++)
        sorted_films_id.push_back(films[i].get_film_rate());
    sort(sorted_films_id.begin(), sorted_films_id.end());
    for(int i=0; i<sorted_films_id.size(); i++)
        sorted_films.push_back(films[sorted_films_id[i]-1]);
    return sorted_films;
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
            users[current_user_index].show_best_films(best_films());
        }
        else
            throw NotFound();
    }
    else
        throw BadRequest();
}

vector<int> CommandHandler::find_search_key_indexes()
{
    check_command_size(3,15);
    check_QuestionMark_command();
    vector<int> indexes{find_element_in_vec(Name,Low), find_element_in_vec(MinRate,Low),  find_element_in_vec(MinYear,Low),
                        find_element_in_vec(Price,Low), find_element_in_vec(MaxYear,Low), find_element_in_vec(Director,Low)};
    return indexes;
}

void CommandHandler::show_all_films_detail()
{
    for(int i=0; i<films.size(); i++)
        films[i].show_search_film_details(i);
}

void CommandHandler::edit_search_films_features()
{
    vector<int> indexes = find_search_key_indexes();
    string name = (indexes[0] != 0) ? current_command[indexes[0]+1] : EmptyString;
    int min_rate = (indexes[1] != 0) ? convert_string_to_int(current_command[indexes[1]+1]) : EmptyInt;
    int min_year = (indexes[2] != 0) ? convert_string_to_int(current_command[indexes[2]+1]) : EmptyInt;
    int price = (indexes[3] != 0) ? convert_string_to_int(current_command[indexes[3]+1]) : EmptyInt;
    int max_year = (indexes[4] != 0) ? convert_string_to_int(current_command[indexes[4]+1]) : EmptyInt;
    string director = (indexes[5] != 0) ? current_command[indexes[5]+1] : EmptyString;
   // search_films_user(name,min_year,max_year,min_rate,price,director);
    
}
/*
vector<int> CommandHandler::find_features_films(vector<int> input_ids, int feature)
{

}
*/
//void CommandHandler::search_films_user(string _name, int _min_year, int _max_year, int _min_rate, int _price, string _director)
void CommandHandler::search_films_user()
{/*
    vector<int> fims_id;
    if(_name != EmptyString)
    {
        for(int i=0; i<films.size(); i++)
        {
            if(_name == films[i].get_film_name())
                films_id.push_back(films[i].get_film_id());
        }
    }*/
}

void CommandHandler::show_readed_notifications_user()
{
cerr << "I";
}

void CommandHandler::show_notifications_user()
{
cerr << "I";
}

void CommandHandler::show_followers_list_publisher()
{
    check_command_size(2,2);
    if(role == Publisher_word)
        publishers[current_publisher_index].show_followers();
}

void CommandHandler::show_published_films_publisher()
{
cerr << "I";
}

void CommandHandler::show_buyed_films_user()
{
cerr << "I";
}

void CommandHandler::delete_film_publisher()
{
cerr << "I";
}

void CommandHandler::delete_comment_publisher( )
{
cerr << "I";
}
