#include "Comment.h"

using namespace std;

Comment::Comment(std::string _comment)
{  
    comment = _comment;
    comment_status = Available;
}

void Comment::reply_comment_message(std::string _reply_comment)
{
    reply_comments.push_back(_reply_comment);
}

string Comment::get_comment()
{
    return comment;
}

vector<string> Comment::return_reply_comments()
{
    return reply_comments;
}

void Comment::set_comment_status(std::string _status)
{
    comment_status = _status;
}

string Comment::get_comment_status()
{
    return comment_status;
}
