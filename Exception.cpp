#include "Exceptions.h"
#include <iostream>

const char* NotFound::what() const noexcept
{
    std::cerr<< "Not Found" << std::endl;
}

const char* BadRequest::what() const noexcept
{
    std::cerr<< "Bad Requst" << std::endl;
}

const char* PremissionDenied::what() const noexcept
{
    std::cerr<< "Premission Denied" << std::endl;
}

