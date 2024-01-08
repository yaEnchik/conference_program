#ifndef FILE_READER_H
#define FILE_READER_H

#include "conference_structure.h"

void readFromFile(const char* file_name, conference_structure* array[], int& size);

#endif