#include "sort.h"
#include <iostream>


int compare_by_time(conference_structure* first, conference_structure* second) {
	if (conference_structure::delta_time(first->startTime, second->endTime) == 0) {
		return 0;
	}
	else if (conference_structure::delta_time(first->startTime, second->endTime) > 0) {
		return 1;
	}
	else {
		return -1;
	}
}

int compare_by_lastname(conference_structure* first, conference_structure* second) {
	return 0;
}