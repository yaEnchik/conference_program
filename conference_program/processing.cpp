#include <iostream>

#include "processing.h"

std::string get_longest_theme(conference_structure* array[], int size) {
	conference_structure* result = array[0];
	for (int i = 0; i <= size - 1; i++) {
		if (compare_by_time(array[i], result) == 1) {
			result = array[i];
		}
	}
	long ElapsedTime = conference_structure::delta_time(result->startTime, result->endTime);
	long M = ElapsedTime;        //Общее число минут
	long S = ElapsedTime - (M * 60);  //Число секунд
	long H = M / 60;                  //Число часов
	M = M - (H * 60);            //Число минут
	std::string result_string = H < 10 ? "0" + std::to_string(H) + ":" + std::to_string(M) : std::to_string(H) + ":" + std::to_string(M);
	return result_string;
}