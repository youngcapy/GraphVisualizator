#include "InfoOps.h"



void InfoOps::greetings()
{
	std::cout << "========================================" << std::endl;
	std::cout << "================Hello!==================" << std::endl;
	std::cout << "==============Welcome to================" << std::endl;
	std::cout << "===========Sorts visualizer=============" << std::endl;
	std::cout << "========================================" << std::endl;
}

void InfoOps::info()
{

	std::cout << std::endl;
	std::cout << "This app represents the visual implementation of sorting process" << std::endl;
	std::cout << "It supports BubbleSort(without optimizations), SelectionSort, MergeSort(In development)," << std::endl;
	std::cout << "QuickSort and BogoSort(My favorite one)." << std::endl;
	std::cout << "\n\n=WARNING=\n\nInteger inputs are strongly recommended due to problems with visualizations of float" << std::endl;
	std::cout << "values or char values as well. It will be more convenient to enter small nums from -10 to 10" << std::endl;
	std::cout << "just to get a general idea of every algorithm.\n\n===Good luck!===\n\n" << std::endl;

}

int InfoOps::choose_sort()
{
	std::cout << "\n========================================\n" << std::endl;
	std::cout << "CHOOSE SORT:\n" << std::endl;
	std::cout << "1. BubbleSort" << std::endl;
	std::cout << "2. SelectionSort" << std::endl;
	std::cout << "3. QuickSort" << std::endl;
	std::cout << "4. BogoSort" << std::endl;
	std::cout << "\n========================================\n" << std::endl;

	int result{};
	std::cin >> result;
	if (result <= 0 || result > 4) {
		std::cout << "Wrong number" << std::endl;
		return -1;
	}
	return result;

}

void InfoOps::print_array(int* arr, size_t size) {

	std::cout << "==============Your array================\n" << std::endl;

	for (unsigned i{}; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========================================\n" << std::endl;

}



