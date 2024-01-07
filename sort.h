#ifndef SORT_H
#define SORT_H

#include "conference_structure.h"

int compare_by_time(conference_structure* first, conference_structure* second);

int compare_by_lastname(conference_structure* first, conference_structure* second);

void heap_sort(conference_structure* array[], int size, int (*check)(conference_structure* first, conference_structure* second));

void merge_sort(conference_structure* array[], int low, int high, int (*check)(conference_structure* first, conference_structure* second));

#endif