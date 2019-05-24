
#ifndef __UT_H__
#define __UT_H__

#include <iostream>
#include <string>
#include <vector>





class Ut 
{
public:
  Ut(int _user_id); 
  std::string get_username();
  
private:
  std::string username;
	std::string password;
  std::string email;
  int age;
  int user_id;
};

#endif