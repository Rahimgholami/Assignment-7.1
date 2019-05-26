#ifndef __NOTIFICATIONS_H__
#define __NOTIFICATIONS_H__

#include <iostream>
#include <vector>
#include <string>
#include "Define.h"

class Notifications
{
public:
    Notifications(int _publisher_id, std::string _publisher_name, int _user_id, std::string _username, int _film_id, std::string _film_name, std::string _type);
    void reply_comment_notification(int _publisher_id, std::string _publisher_name);
    void register_film_notification(int _publisher_id, std::string _publisher_name);
    void follower_notification(std::string _username, int _user_id);
    void buy_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id);
    void rate_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id);
    void comment_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id);
    void show_notification(std::string _notificaiton_status, int &index);
    void print_notificaion();
private:
    std::string user_name;
    std::string publisher_name;
    std::string film_name;
    std::string notification_type;
    std::string notification_status;
    int user_id;
    int publisher_id;
    int film_id;
};

#endif