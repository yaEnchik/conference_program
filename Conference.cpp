#include <iostream>

using namespace std;

#include "conference_structure.h"
#include "file_reader.h"
#include "constants.h"

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
