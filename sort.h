#ifndef SORT_H
#define SORT_H

#include "conference_structure.h"

int compare_by_time(conference_structure* first, conference_structure* second);

int compare_by_lastname(conference_structure* first, conference_structure* second);

void heapSort(conference_structure* array[], int n, int (*check)(conference_structure* first, conference_structure* second));

#endif