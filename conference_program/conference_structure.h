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

    static int delta_time(std::string t1, std::string t2)
    {
        const int N = 60;
        int Amin, Bmin;
        Amin = atoi(t1.substr(0, 2).c_str()) * N + atoi(t1.substr(3, 2).c_str());
        Bmin = atoi(t2.substr(0, 2).c_str()) * N + atoi(t2.substr(3, 2).c_str());
        return Bmin - Amin;
    }
};

#endif