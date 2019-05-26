#ifndef __COMMENT_H__
#define __COMMENT_H__

#include <iostream>
#include <vector>
#include <string>
#include "Define.h"

class Comment
{
public:
    Comment(std::string _comment, int _user_id);
    void reply_comment_message(std::string _reply_comment);
    std::string get_comment();
    std::vector<std::string> return_reply_comments();
    std::string get_comment_status();
    int get_user_id();
    void set_comment_status(std::string _status);
private:
    std::string comment;
    std::vector<std::string> reply_comments;
    std::string comment_status;
    int user_commented_id;
};

#endif