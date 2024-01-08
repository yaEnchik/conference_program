#include <iostream>

#include "processing.h"

conference_structure* get_longest_theme(conference_structure* array[], int size) {
	conference_structure* result = array[0];
	for (int i = 0; i <= size - 1; i++) {
		if (compare_by_time(array[i], result) == 1) {
			result = array[i];
		}
	}
	return result;
}