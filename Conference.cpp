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
    cout << conference->startTime << '\n';
    cout << conference->endTime << '\n';
    cout << conference->member.first_name << '\n';
    cout << conference->member.last_name << '\n';
    cout << conference->member.middle_name << '\n';
    cout << conference->theme;
    /**********   **********/
	cout << '\n';
	cout << '\n';
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #1. GIT\n";
    cout << "Variant #2. Conference program\n";
    cout << "Author: Yana Aniskova\n";
    conference_structure* conferences[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        readFromFile("data.txt", conferences, size);
        cout << "----------Все участники----------" << '\n';
        for (int i = 0; i < size; i++)
        {
            cout << conferences[i]->startTime << '\n';
            cout << conferences[i]->endTime << '\n';
            cout << conferences[i]->member.last_name << '\n';
            cout << conferences[i]->member.first_name << '\n';
            cout << conferences[i]->member.middle_name << '\n';
            cout << conferences[i]->theme << '\n';
            cout << '\n';
        }
        cout << "--------------------------" << '\n';
        cout << "----------Сравнение по дате----------" << '\n';
        cout << compare_by_time(conferences[2], conferences[1]) << '\n';
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
