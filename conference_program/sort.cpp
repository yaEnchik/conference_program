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

void heap_sort(conference_structure* array[], int size, int (*check)(conference_structure* first, conference_structure* second))
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i, check);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0, check);
    }
}

void merge(conference_structure* arr[], int l, int m, int r, int (*check)(conference_structure* first, conference_structure* second)) {
    int n1 = m - l + 1;
    int n2 = r - m;

    conference_structure** L = new conference_structure * [n1];
    conference_structure** R = new conference_structure * [n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0;

    int k = l;
    while (i < n1 && j < n2) {
        if (check(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void merge_sort(conference_structure* array[], int l, int r, int (*check)(conference_structure* first, conference_structure* second)) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(array, l, m, check);
        merge_sort(array, m + 1, r, check);
        merge(array, l, m, r, check);
    }
}