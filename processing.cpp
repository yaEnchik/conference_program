#include <iostream>

#include "processing.h"

conference_structure* get_longest_theme(conference_structure* array[], int size, int (*check)(conference_structure* first, conference_structure* second)) {
	conference_structure* result = array[0];
	for (int i = 0; i <= size; i++) {
		if (check(array[i], result) == 1) {
			result = array[i];
		}
	}
	return result;
}