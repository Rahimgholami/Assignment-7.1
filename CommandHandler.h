#ifndef COMMAND_HANDLER_H_
#define COMMAND_HANDLER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <iterator>
#include "Exception.h"
#include "Define.h"
#include "Publisher.h"
#include "User.h"
#include "Film.h"

class CommandHandler
{
public:

  CommandHandler();
  void logout_user();
  void show_user_money();
  int get_whole_money();
  void add_command(std::vector<std::string> input_command);
  int convert_string_to_int(std::string input_string);
  void check_command_size(int min_size, int max_size);
  int find_element_in_vec(std::string search_element, int priority);
  void check_QuestionMark_command();
  std::vector<int> find_signup_key_indexes();
  static void is_email_valid(const std::string& email);
  void check_uniqueness(std::vector<int> key_indexes, int age);
  void add_user_publisher_to_vector(std::vector<int> key_indexes, int age);
  void signup();
  void login();
  void check_login_command();
  bool user_search();
  bool publisher_search();  
  int convert_user_id_to_index(int _user_id);
  int convert_publisher_id_to_index(int _publisher_id);
  std::vector<int> inverse_vector(std::vector<int> input_vector);
  void rate_films(int _film_id, int score);
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
  void check_user_money_sufficency(int _film_price);
  void add_follwer_details(int _following_id, int _follower_index);
  void add_following_user();
  void buy_film_user();
  void rate_film_user();
  std::vector<int> find_edit_film_key_indexes();
  void edit_film_publisher();
  std::vector<int> find_best_films();
  void show_film_details_user();
  void show_best_films(std::vector<int> _best_films_id);
  void process_best_films(std::vector<int> _best_films_id);
  void show_all_films_detail();
  std::vector<int> find_search_key_indexes();
  void edit_search_films_features();
  void search_films_user();
  void check_buy_exceptions(int _film_id);
  void send_notification_to_followers(std::string _type);
  void send_notification_to_followers(int id);
  std::vector<int> filter_search(std::string _name, int min_rate, int min_year, int max_year, std::string _director, int _price);
  std::vector<int> find_films_name(std::vector<int> input_ids, std::string _name);
  std::vector<int> find_films_min_rate(std::vector<int> input_ids, int _min_rate);
  std::vector<int> find_films_min_year(std::vector<int> input_ids, int _min_year);
  std::vector<int> find_films_max_year(std::vector<int> input_ids, int _max_year);
  std::vector<int> find_films_director(std::vector<int> input_ids, std::string _director);
  std::vector<int> find_films_price(std::vector<int> input_ids, int _price);
  std::vector<int> find_common_elements(std::vector<int> vec1, std::vector<int> vec2);
  std::vector<int> filtered_vector(std::vector<int> vec1 , std::vector<int> vec2, std::vector<int> vec3, std::vector<int> vec4, std::vector<int> vec5, std::vector<int> vec6);
  void show_search(std::vector<int> ids);
  std::vector<int> process_find_elements();
  void show_search_user(std::vector<int> ids);
  std::vector<int> process_buy_elements();
  std::vector<int> check_user_films(std::vector<int> _film_ids);
  std::vector<int> sort_films_rate(std::vector<int> sorted_films_id, std::vector<int> sorted_film_rate);
  void edit_films(int _film_id, std::string _film_name, int _film_year, int _film_length, std::string _film_summary, std::string _film_director);
  void show_readed_notifications_user();
  void show_notifications_user();
  void show_followers_list_publisher();
  void show_published_films_publisher();
  void show_buyed_films_user();
  void delete_film_publisher();
  void delete_comment_publisher( );
  std::vector<int> search_film_feature(int min_year, int max_year);
  bool is_user_buy_both_films(int _first_film_id, int _second_film_id, int user_id, std::string role);
  std::vector<int> best_films_matrix(int n, int k);
  void add_matrix_elements(int _first_id, int _second_id, std::vector<std::vector<int>> &film_matrix);
  std::vector<int> sort_best_films(std::vector<int> best_films);

private:

  std::vector<std::string> current_command;
  std::vector<User> users;
  std::vector<Publisher> publishers;
  std::vector<Film> films;
  std::string role;
  std::string admin_status;
  int current_user_id;
  int current_publisher_id;
  int current_user_index;
  int current_publisher_index;
};


#endif
