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
	long M = ElapsedTime;        //����� ����� �����
	long S = ElapsedTime - (M * 60);  //����� ������
	long H = M / 60;                  //����� �����
	M = M - (H * 60);            //����� �����
	std::string hours = H < 10 ? "0" + std::to_string(H) : std::to_string(H);
	std::string minutes = M < 10 ? "0" + std::to_string(M) : std::to_string(M);
	std::string result_string = hours + ":" + minutes;
	return result_string;
}