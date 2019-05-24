

#include<iostream>




#include "Ut.h"

using namespace std;

Ut::Ut(int _user_id)
{
    email ="@";
    username = "R";
    password = "T";
    age = 5;
    user_id = _user_id;
}

string Ut::get_username()
{
    return username;
}

