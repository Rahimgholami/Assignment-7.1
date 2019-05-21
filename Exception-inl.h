#ifndef EXCEPTION_INL_H_
#define EXCEPTION_INL_H_
/*
#ifndef EXCEPTION_H_
#error "Exception-inl.h" should be included only in "Exception.h" file.
#endif
*/
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
    return "Premission Denied";
}

#endif