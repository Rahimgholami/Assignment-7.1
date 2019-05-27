#ifndef EXCEPTION_INL_H_
#define EXCEPTION_INL_H_


#include "Exception.h"

const char* NotFound::what() const throw()
{
    return "Not Found";
}

const char* BadRequest::what() const throw()
{
    return "Bad Request";
}

const char* PremissionDenied::what() const throw()
{
    return "Permission Denied";
}

#endif