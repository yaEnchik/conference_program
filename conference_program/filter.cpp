#include "filter.h"
#include <cstring>
#include <iostream>

conference_structure** filter(conference_structure* array[], int size, bool (*check)(conference_structure* element), int& result_size) {
	conference_structure** result = new conference_structure * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;

}

bool check_conference_by_name(conference_structure* element)
{
	return strcmp(element->member.last_name, "Иванов") == 0 && 
			strcmp(element->member.first_name, "Иван") == 0 && 
			strcmp(element->member.middle_name, "Иванович") == 0;
}

bool check_conference_by_time(conference_structure* element)
{
	if (conference_structure::delta_time(element->startTime, element->endTime) >= 15) {
		return true;
	}
	return false;
}

