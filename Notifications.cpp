#include "Notifications.h"

using namespace std;


 Notifications::Notifications(){};

void Notifications::reply_comment_notification(int _publisher_id, std::string _publisher_name)
{
    publisher_id = _publisher_id;
    publisher_name = _publisher_name;
    notification_status = UnReaded;
    notification_type = ReplyNotification;
}
    
void Notifications::register_film_notification(int _publisher_id, std::string _publisher_name)
{
    publisher_id = _publisher_id;
    publisher_name = _publisher_name;
    notification_status = UnReaded;
    notification_type = RegisterNotification;
}

void Notifications::follower_notification(std::string _username, int _user_id)
{
    user_id = _user_id;
    user_name = _username;
    notification_status = UnReaded;
    notification_type = FollowNotification;

}
    
void Notifications::buy_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id)
{
    user_id = _user_id;
    user_name = _username;
    film_id = _film_id;
    film_name = _film_name;
    notification_status = UnReaded;
    notification_type = BuyNotificatoin;    
}

void Notifications::rate_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id)
{
    user_id = _user_id;
    user_name = _username;
    film_id = _film_id;
    film_name = _film_name;
    notification_status = UnReaded;
    notification_type = RateNotification;  
}

void Notifications::comment_film_notification(std::string _username, int _user_id, std::string _film_name, int _film_id)
{
    user_id = _user_id;
    user_name = _username;
    film_id = _film_id;
    film_name = _film_name;
    notification_status = UnReaded;
    notification_type = CommentNotification;  
}

void Notifications::show_notification(std::string _notificaiton_status)
{
    if(_notificaiton_status == notification_status)
        print_notificaion();
}

void Notifications::print_notificaion()
{
    if(notification_type == ReplyNotification)
        cout << PublisherShow << Space << publisher_name << Space << WithId << Space << publisher_id << Space << ReplyToYourComment << endl;
    else if(notification_type == RegisterNotification)
        cout << PublisherShow << Space << publisher_name << Space << WithId << Space << publisher_id << Space << RegisterNewFile << endl;
    else if(notification_type == FollowNotification)
        cout << UserShow << Space << user_name << Space << WithId << Space << user_id << Space << FollowYou << endl;
    else if(notification_type == BuyNotificatoin)
        cout << UserShow << Space << user_name << Space << WithId << Space << user_id << Space 
            << BuyYourFilm << Space << film_name << Space << WithId << Space << film_id << endl;
    else if(notification_type == RateNotification)
        cout << UserShow << Space << user_name << Space << WithId << Space << user_id << Space 
            << RateYourFilm << Space << film_name << Space << WithId << Space << film_id << endl;
    else if(notification_type == CommentNotification)
        cout << UserShow << Space << user_name << Space << WithId << Space << user_id << Space 
            << CommentOnYourFilm << Space << film_name << Space << WithId << Space << film_id << endl;  
}