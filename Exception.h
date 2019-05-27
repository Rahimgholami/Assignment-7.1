#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class NotFound : public std::exception
{
public:
    inline const char* what() const throw();
};

class BadRequest : public std::exception
{
public:
    inline const char* what() const throw();
};

class PremissionDenied : public std::exception
{
public:
    inline const char* what() const throw();
};

#include "Exception-inl.h"


#endif