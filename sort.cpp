#include "sort.h"
#include <iostream>

using namespace std;

int compare_by_time(conference_structure* first, conference_structure* second) {
	if (conference_structure::delta_time(first->startTime, first->endTime) - conference_structure::delta_time(second->startTime, second->endTime) == 0) {
		return 0;
	}
	else if (conference_structure::delta_time(first->startTime, first->endTime) - conference_structure::delta_time(second->startTime, second->endTime) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare_by_lastname(conference_structure* first, conference_structure* second) {
	string first_lastname = first->member.last_name;
	string second_lastname = second->member.last_name;
	if (first_lastname.compare(second_lastname) == 0) {
		string first_theme = first->theme;
		string second_theme = second->theme;
		return first_theme.compare(second_theme);
	}
	return first_lastname.compare(second_lastname);
}

void heapify(conference_structure* array[], int n, int i, int (*check)(conference_structure* first, conference_structure* second))
{
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2;

    if (l < n && check(array[l], array[largest]) == 1)
        largest = l;

    if (r < n && check(array[r], array[largest]) == 1)
        largest = r;

    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, n, largest, check);
    }
}

void heapSort(conference_structure* array[], int n, int (*check)(conference_structure* first, conference_structure* second))
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i, check);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0, check);
    }
}