#ifndef CONFERENCE_STRUCTURE_H
#define CONFERENCE_STRUCTURE_H

#include "constants.h"

struct time
{
    int hour;
    int minute;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct conference_structure
{
    person member;
    time start;
    time finish;
    char theme[MAX_STRING_SIZE];
};

#endif