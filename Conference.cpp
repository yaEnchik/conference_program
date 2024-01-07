#include <iostream>

using namespace std;

#include "conference_structure.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"

void output(conference_structure* conference)
{
	/**********   **********/
    cout << conference->startTime << ' ';
    cout << conference->endTime << ' ';
    cout << conference->member.last_name << ' ';
    cout << conference->member.first_name << ' ';
    cout << conference->member.middle_name << ' ';
    cout << conference->theme;
    /**********   **********/
	cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Яна Аниськова\n";
    cout << '\n';
    conference_structure* conferences[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        readFromFile("data.txt", conferences, size);
        cout << "----------Все участники----------" << '\n';
        for (int i = 0; i < size; i++)
        {
            output(conferences[i]);
        }
        cout << "--------------------------" << '\n';
        cout << "----------Сравнение по дате----------" << '\n';
        cout << compare_by_time(conferences[1], conferences[2]) << '\n';
        cout << "--------------------------" << '\n';
        cout << "----------Сравнение по фамилии----------" << '\n';
        cout << compare_by_lastname(conferences[1], conferences[0]) << '\n';
        cout << "--------------------------" << '\n';
        int new_size;
        cout << "----------Фильтр по имени----------" << '\n';
        conference_structure** filteredByName = filter(conferences, size, check_conference_by_name, new_size);
        for (int i = 0; i < new_size; i++)
        {
            output(filteredByName[i]);
        }
        delete[] filteredByName;
        cout << "--------------------------" << '\n';
        cout << "----------Фильтр по минутам----------" << '\n';
        conference_structure** filteredByTime = filter(conferences, size, check_conference_by_time, new_size);
        for (int i = 0; i < new_size; i++)
        {
            output(filteredByTime[i]);
        }
        delete[] filteredByTime;
        cout << "--------------------------" << '\n';
        cout << "----------Пирамидальная сортировка по фамилии----------" << '\n';
        heapSort(conferences, size, compare_by_lastname);
        for (int i = 0; i < size; i++)
        {
            output(conferences[i]);
        }
        cout << "--------------------------" << '\n';
        cout << "----------Пирамидальная сортировка по времени----------" << '\n';
        heapSort(conferences, size, compare_by_time);
        for (int i = 0; i < size; i++)
        {
            output(conferences[i]);
        }
        cout << "--------------------------" << '\n';
        for (int i = 0; i < size; i++)
        {
            delete conferences[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
}
