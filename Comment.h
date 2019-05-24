#ifndef __COMMENT_H__
#define __COMMENT_H__

#include <iostream>
#include <vector>
#include <string>

class Comment
{
public:
    Comment(std::string _comment);
    void reply_comment_message(std::string _reply_comment);
private:
    std::string comment;
    std::vector<std::string> reply_comments;
};

#endif