#ifndef FILTER_H
#define FILTER_H

#include "conference_structure.h"

conference_structure** filter(conference_structure* array[], int size, bool (*check)(conference_structure* element), int& result_size);

bool check_conference_by_name(conference_structure* element);

bool check_conference_by_time(conference_structure* element);

#endif