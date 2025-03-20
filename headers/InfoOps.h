#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class InfoOps
{

	public:

		InfoOps() = delete;
		InfoOps(const InfoOps&) = delete;
		InfoOps(InfoOps&&) = delete;

		static void greetings();

		static void info();
		static int choose_sort();
		
		static void print_array(int* arr, size_t size);

};

