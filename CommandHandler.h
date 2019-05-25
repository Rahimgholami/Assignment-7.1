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
#include "Film.h"

class CommandHandler
{
public:
  CommandHandler();
  void add_command(std::vector<std::string> input_command);

  int convert_string_to_int(std::string input_string);
  void check_command_size(int min_size, int max_size);
  int find_element_in_vec(std::string search_element, int priority);
  void check_QuestionMark_command();

  std::vector<int> find_signup_key_indexes();
  static void is_email_valid(const std::string& email);
  
  void add_user_publisher_to_vector(std::vector<int> key_indexes, int age);
  void signup();
  
  void login();
  void check_login_command();
  bool user_search();
  bool publisher_search();  
    

  void check_increase_money();
  int convert_money_to_int();
  void increase_money_user();


  void increase_money_publisher();

  void add_film_to_vector(std::vector<int> key_indexes);
  std::vector<int> find_add_film_publisher_key_indexes();
  void add_film_publisher();

  std::vector<int> find_comment_user_key_indexes();
  void comment_user();

  std::vector<int> find_reply_comment_key_indexes();
  void reply_comment_publisher();



  void add_follower_user();

  void buy_film_user();
  
  void rate_film_user();
  
  std::vector<int> find_edit_film_key_indexes();
  void edit_film_publisher();

  std::vector<Film> best_films();
  void show_film_details_user();

  void show_all_films_detail();
  std::vector<int> find_search_key_indexes();
  void edit_search_films_features();
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
    int current_publisher_id;
    int current_user_index;
    int current_publisher_index;
};


#endif
