#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class NotFound : public std::exception
{
    const char* what() const noexcept;
};

class BadRequest : public std::exception
{
    const char* what() const noexcept;
};

class PremissionDenied : public std::exception
{
    const char* what() const noexcept;
};

#endif