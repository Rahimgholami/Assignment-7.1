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

class CommandHandler
{
public:
    CommandHandler();
    static bool is_email_valid(const std::string& email);
    void check_signup_command_size();
    int find_element_in_vec(std::string search_element, int priority);
    void check_signup_command();
    //void add_command(std::vector<std::string> input_command);
    //void process_command();
    User get_user(int _user_id);
    Publisher get_publisher(int _publisher_id);

  void increase_money_user(std::vector<std::string> current_command);
  void increase_money_publisher(std::vector<std::string> current_command);
  void signup(std::vector<std::string> current_command);
  void login(std::vector<std::string> current_command);
  void add_film_publisher(std::vector<std::string> current_command);
  void reply_comment_publisher(std::vector<std::string> current_command);
  void add_follower_user(std::vector<std::string> current_command);
  void buy_film_user(std::vector<std::string> current_command);
  void rate_film_user(std::vector<std::string> current_command);
  void comment_user(std::vector<std::string> current_command);
  void edit_film_publisher(std::vector<std::string> current_command);
  void show_film_details_user(std::vector<std::string> current_command);
  void search_films_user(std::vector<std::string> current_command);
  void show_readed_notifications_user(std::vector<std::string> current_command);
  void show_notifications_user(std::vector<std::string> current_command);
  void show_followers_list_publisher(std::vector<std::string> current_command);
  void show_published_films_publisher(std::vector<std::string> current_command);
  void show_buyed_films_user(std::vector<std::string> current_command);
  void delete_film_publisher(std::vector<std::string> current_command);
  void delete_comment_publisher( std::vector<std::string> current_command);
 
private:
  //  std::vector<std::string> current_command;
    std::vector<User> users;
    std::vector<Publisher> publishers;
    std::vector<Film> films;
    std::string user_role;
    int current_user_id;
};


#endif
