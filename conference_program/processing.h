#ifndef PROCESSING_H
#define PROCESSING_H

#include "conference_structure.h"

conference_structure* get_longest_theme(conference_structure* array[], int size, int (*check)(conference_structure* first, conference_structure* second));

#endif