#ifndef CONFERENCE_STRUCTURE_H
#define CONFERENCE_STRUCTURE_H

#include <string>

#include "constants.h"

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct conference_structure
{
    std::string startTime;
    std::string endTime;
    person member;
    char theme[MAX_STRING_SIZE];
};

#endif