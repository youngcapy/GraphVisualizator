// SortsVisualization.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "SortMaster.h"
#include "InfoOps.h"

int main()
{
    std::array<int, 3> point = { 1, 2, -3 };
    int array[]{ -4, 10, 9, 8, -10 };
    SortMaster<int> sm{array, 5, 1};
    InfoOps::greetings();
    InfoOps::info();
    InfoOps::print_array(array, 5);
    sm.sort_master(InfoOps::choose_sort() - 1);

}

