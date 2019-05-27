
#ifndef __USER_H__
#define __USER_H__

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Define.h"
#include "Exception.h"
#include "Film.h"
#include "Notifications.h"

class User {

public:
  User(std::string _email, std::string _username, std::string _password, int _age, int _user_id); 
  std::string get_username();
  std::string get_password();
  int get_user_id();
  std::vector<int> get_buyed_films_id();
  std::string get_email();
  int get_money();    
  void increase_money(int money_amount);
  void buy_film(int film_id, int _film_price);
  void rate_films(Film _film, int _film_id, int score);
  void show_notification();
  void show_readed_notification();
  void add_following(int _following_id);
  void add_notification(int _publisher_id, std::string _publisher_name, int _user_id, std::string _username, int _film_id, std::string _film_name, std::string _type);
  std::vector<int> check_buyed_films(std::vector<int> _film_ids);
private:
  std::string username;
	std::string password;
  std::string email;
  int age;
  int money;
  int user_id;
  std::vector<Notifications> notification;
  std::vector<int> followers_id;
  std::vector<int> buyed_films_id;
};

#endif