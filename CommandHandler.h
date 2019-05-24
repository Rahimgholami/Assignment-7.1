#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include "Exception.h"
#include "Define.h"
#include "Publisher.h"
#include "User.h"

class CommandHandler
{
public:
    CommandHandler();
    void check_command_size(int min_size, int max_size);


    std::vector<int> find_signup_key_indexes();
    static void is_email_valid(const std::string& email);
    
    int find_element_in_vec(std::string search_element, int priority);
    void check_signup_command();
    void add_command(std::vector<std::string> input_command);
    //void process_command();
    User get_user(int _user_id);
    Publisher get_publisher(int _publisher_id);
    void signup();

  void increase_money_user();
  void increase_money_publisher();
  
  void login();
  void add_film_publisher();
  void reply_comment_publisher();
  void add_follower_user();
  void buy_film_user();
  void rate_film_user();
  void comment_user();
  void edit_film_publisher();
  void show_film_details_user();
  void search_films_user();
  void show_readed_notifications_user();
  void show_notifications_user();
  void show_followers_list_publisher();
  void show_published_films_publisher();
  void show_buyed_films_user();
  void delete_film_publisher();
  void delete_comment_publisher( );
 
private:
    std::vector<std::string> current_command;
    std::vector<User> users;
    std::vector<Publisher> publishers;
    std::vector<Film> films;
    std::string role;
    int current_user_id;
};


#endif
