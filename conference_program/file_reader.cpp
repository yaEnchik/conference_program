#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

void readFromFile(const char* file_name, conference_structure* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            conference_structure* item = new conference_structure;
            file >> item->startTime;
            file >> item->endTime;
            file >> item->member.last_name;
            file >> item->member.first_name;
            file >> item->member.middle_name;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            file.getline(item->theme, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}