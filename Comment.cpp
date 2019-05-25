#include "Comment.h"

using namespace std;

Comment::Comment(std::string _comment)
{  
    comment = _comment;
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