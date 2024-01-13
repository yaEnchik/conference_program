#include <iostream>

using namespace std;

#include "conference_structure.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
#include "processing.h"

void output(conference_structure* conference)
{
    cout << conference->startTime << ' ';
    cout << conference->endTime << ' ';
    cout << conference->member.last_name << ' ';
    cout << conference->member.first_name << ' ';
    cout << conference->member.middle_name << ' ';
    cout << conference->theme;
	cout << '\n';
}
void show_menu() 
{
    cout << "------Меню------" << '\n';
    cout << "1. Вывод всех конференций" << '\n';
    cout << "2. Отсортировать пиамидальной сортировкой по фамилии" << '\n';
    cout << "3. Отсортировать пиамидальной сортировкой по времени" << '\n';
    cout << "4. Отсортировать сортировкой слиянием по фамилии" << '\n';
    cout << "5. Отсортировать сортировкой слиянием по времени" << '\n';
    cout << "6. Вывести все доклады Иванова Ивана Ивановича" << '\n';
    cout << "7. Вывести все доклады длительностью больше 15 минут" << '\n';
    cout << "Введите -1 чтобы закончить программу" << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа #1. GIT\n";
    cout << "Вариант #2. Программа конференции\n";
    cout << "Автор: Яна Аниськова\n";
    cout << '\n';
    conference_structure* conferences[MAX_FILE_ROWS_COUNT];
    conference_structure** conferences_filter = new conference_structure*[0];
    int size;
    try
    {
        readFromFile("data.txt", conferences, size);
        show_menu();
        int choise;
        int filter_size = 0;
        cin >> choise;
        while (choise != -1) 
        {
            switch (choise) {
            case 1:
                system("cls");
                cout << "----------Все участники----------" << '\n';
                for (int i = 0; i < size; i++)
                {
                    output(conferences[i]);
                }
                cout << "----------Самая длиная конференция----------" << '\n';
                cout << get_longest_theme(conferences, size) << "\n";
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 2:
                system("cls");
                cout << "----------Пирамидальная сортировка по фамилии----------" << '\n';
                heap_sort(conferences, size, compare_by_lastname);
                for (int i = 0; i < size; i++)
                {
                    output(conferences[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 3:
                system("cls");
                cout << "----------Пирамидальная сортировка по времени----------" << '\n';
                heap_sort(conferences, size, compare_by_time);
                for (int i = 0; i < size; i++)
                {
                    output(conferences[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 4:
                system("cls");
                cout << "----------Сортировка слиянием по фамилии----------" << '\n';
                merge_sort(conferences, 0, size - 1, compare_by_lastname);
                for (int i = 0; i < size; i++)
                {
                    output(conferences[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 5:
                system("cls");
                cout << "----------Сортировка слиянием по времени----------" << '\n';
                merge_sort(conferences, 0, size - 1, compare_by_time);
                for (int i = 0; i < size; i++)
                {
                    output(conferences[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 6:
                system("cls");
                cout << "----------Доклады Иванова Ивана Ивановича----------" << '\n';
                conferences_filter =  filter(conferences, size, check_conference_by_name, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(conferences_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            case 7:
                system("cls");
                cout << "----------Доклады длительностью больше 15 минут----------" << '\n';
                conferences_filter = filter(conferences, size, check_conference_by_time, filter_size);
                for (int i = 0; i < filter_size; i++)
                {
                    output(conferences_filter[i]);
                }
                cout << '\n';
                cout << '\n';
                show_menu();
                cin >> choise;
                break;
            default:
                cout << "Такого пункта нет!" << '\n';
                show_menu();
                cin >> choise;
                break;
            }
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
