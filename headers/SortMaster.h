#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <thread>
#include <cstdarg>
#include <vector>
#include <array>
#include <functional>

template
<typename Type>

class SortMaster
{

public:
	SortMaster() = delete;
	SortMaster(Type* array, size_t arr_size, int sleep_seconds);

	void sort_master(int sort);




private:

	void bubble_sort();
	void selection_sort();
	void quick_sort(); // To call
	void merge_sort(); // To call
	void bogo_sort(); // Humour

	

	typedef void (SortMaster<Type>::* SortFunction)();

	SortFunction sortFunctions[4]{ &SortMaster<Type>::bubble_sort, &SortMaster<Type>::selection_sort, &SortMaster<Type>::quick_sort, &SortMaster<Type>::bogo_sort};



	void merge_sort(Type* begin, Type* end); // To use
	void quick_sort(Type* begin, Type* end); // To use
	void state_visualizer();
	void state_visualizer(std::vector<Type> indexes);
	void cleaner();
	void dia_borders(Type& num1, Type& num2);
	void doubler(int va_size, ...);
	bool is_sorted();


	size_t size;
	Type* array_to_sort;
	std::pair<Type, Type> borders;
	std::chrono::seconds sleep;


};


template
<typename Type>

void SortMaster<Type>::bubble_sort() {

	unsigned less_check{ 0 };
	state_visualizer();
	cleaner();
	while (less_check != size - 1) {

		for (unsigned i{}; i < size - less_check - 1; i++) {

			doubler(2, i, i + 1);

			if (array_to_sort[i] > array_to_sort[i + 1]) {
				std::swap(array_to_sort[i], array_to_sort[i + 1]);
				doubler(2, i, i + 1);
			}
		}

		less_check++;
	}

	state_visualizer();

}

template
<typename Type>

void SortMaster<Type>::selection_sort()
{
	cleaner();
	state_visualizer();
	cleaner();
	auto current_element{ array_to_sort };
	while (current_element != array_to_sort + size - 1) {
		auto min_index = current_element;
		for (auto minimum_element{ current_element + 1 }; minimum_element < array_to_sort + size; minimum_element++) {
			doubler(2, current_element - array_to_sort, minimum_element - array_to_sort);
			if (*minimum_element < *min_index)
				min_index = minimum_element;

		}

		std::swap(*current_element, *min_index);
		doubler(2, current_element - array_to_sort, min_index - array_to_sort);
		current_element++;

	}

	state_visualizer();


}

template
<typename Type>

void SortMaster<Type>::quick_sort()
{
	cleaner();
	state_visualizer();
	cleaner();
	quick_sort(array_to_sort, array_to_sort + size);
	state_visualizer();
}



template
<typename Type>

void SortMaster<Type>::quick_sort(Type* begin, Type* end) {

	static_assert(std::is_pointer<Type*>::value || std::_Is_iterator<Type*>::value, "Requires pointers/iterators only!");

	if (end - begin < 2)
		return;
	auto pivot = end - 1;
	auto lptr = begin;
	while (lptr < pivot) {
		doubler(3, lptr - array_to_sort, pivot - array_to_sort, lptr - array_to_sort);
		while(*lptr > *pivot) {

			auto temp = *lptr;
			auto index = pivot - array_to_sort;
			for (long long int i{lptr - array_to_sort}; i < index; i++)
				array_to_sort[i] = array_to_sort[i + 1];
			pivot--;		
			array_to_sort[index] = temp;
			doubler(3, lptr - array_to_sort, pivot - array_to_sort, index);

		}
		lptr++;

	}

	quick_sort(begin, pivot);
	quick_sort(pivot + 1, end);


}


template
<typename Type>

void SortMaster<Type>::bogo_sort() {

	bool sorted{ false };
	state_visualizer();

	if (is_sorted())
		return;

	while (!sorted) {
		cleaner();
		std::random_shuffle(array_to_sort, array_to_sort + size);
		sorted = is_sorted();

		state_visualizer();
	}



}


template
<typename Type>

void SortMaster<Type>::merge_sort() {

	std::cout << "Not ready yet!" << std::endl;

}


template
<typename Type>

void SortMaster<Type>::merge_sort(Type* begin, Type* end)
{



}


template
<typename Type>

SortMaster<Type>::SortMaster(Type* array, size_t arr_size, int sleep_seconds) : array_to_sort{ array }, size{ arr_size } {

	auto minmax_pair = std::minmax_element(array_to_sort, array_to_sort + size);
	auto dia_upper_zero = *minmax_pair.second;
	auto dia_below_zero = *minmax_pair.first;
	dia_borders(dia_below_zero, dia_upper_zero);

	sleep = static_cast<std::chrono::seconds>(sleep_seconds);

}

template<typename Type>
inline void SortMaster<Type>::sort_master(int sort)
{

	(this->*sortFunctions[sort])();
	return;

}


template
<typename Type>

void SortMaster<Type>::dia_borders(Type& num1, Type& num2) {

	std::pair<Type, Type> borders{ 0, 0 };

	std::min(num1, num2) >= 0 ? borders.second = 0 : borders.second = std::min(num1, num2);
	std::max(num1, num2) <= 0 ? borders.first = 0 : borders.first = std::max(num1, num2);

	this->borders = borders;

}


template
<typename Type>

void SortMaster<Type>::state_visualizer() {
	Type i{ borders.first };
	auto max_digits = std::max(int(log10(borders.first)) + 1, int(log10(borders.second)) + 1);
	while (i >= borders.second) {

		std::stringstream ss{};
		for (size_t j{}; j < size; j++) {

			if (j == 0) {
				bool is_negative = array_to_sort[j] < 0 ? 1 : 0;
				if (i >= 0 && borders.second < 0 && i >= 0)
					ss << " ";
				auto current_digits = i == 0 ? 1 : int(log10((int)abs(i))) + 1;
				for (int _{}; _ < max_digits - current_digits + is_negative; _++)
					ss << " ";
				ss << i << "   ";
			}

			ss << ((array_to_sort[j] >= 0 && array_to_sort[j] >= i && i >= 0) || (array_to_sort[j] <= 0 && array_to_sort[j] <= i && i <= 0) ? '*' : ' ');




			ss << ' ';

		}

		std::cout << ss.str() << std::endl;

		i--;

	}

	std::this_thread::sleep_for(sleep);

}

template
<typename Type>

void SortMaster<Type>::state_visualizer(std::vector<Type> indexes) {


	int i{ borders.first };
	auto max_digits = std::max(int(log10(borders.first)) + 1, int(log10(borders.second)) + 1);
	while (i >= borders.second) {

		std::stringstream ss{};
		for (size_t j{}; j < size; j++) {

			if (j == 0) {
				bool is_negative = array_to_sort[j] < 0 ? 1 : 0;
				if (i >= 0 && borders.second < 0 && i >= 0)
					ss << " ";
				auto current_digits = i == 0 ? 1 : int(log10((int)abs(i))) + 1;
				for (int _{}; _ < max_digits - current_digits + is_negative; _++)
					ss << " ";
				ss << i << "   ";
			}

			if (std::find(indexes.begin(), indexes.end(), j) == indexes.end())
				ss << ((array_to_sort[j] >= 0 && array_to_sort[j] >= i && i >= 0) || (array_to_sort[j] <= 0 && array_to_sort[j] <= i && i <= 0) ? '*' : ' ');
			else if(std::find(indexes.begin(), indexes.end(), j) != indexes.end() - 1 && std::find(indexes.begin(), indexes.end(), j) != indexes.begin())
				ss << ((array_to_sort[j] >= 0 && array_to_sort[j] >= i && i >= 0) || (array_to_sort[j] <= 0 && array_to_sort[j] <= i && i <= 0) ? '#' : ' ');
			else
				ss << ((array_to_sort[j] >= 0 && array_to_sort[j] >= i && i >= 0) || (array_to_sort[j] <= 0 && array_to_sort[j] <= i && i <= 0) ? '|' : ' ');


			ss << ' ';

		}

		std::cout << ss.str() << std::endl;

		i--;

	}

	std::this_thread::sleep_for(sleep);

}

template
<typename Type>

void SortMaster<Type>::doubler(int va_size, ...) {

	std::vector<Type> indexes{};
	va_list factor;
	va_start(factor, va_size);
	for (int i = 0; i < va_size; i++)
	{

		indexes.push_back(va_arg(factor, int));

	}
	va_end(factor);
	for (size_t i{}; i < 2; i++) {
		state_visualizer(indexes);
		cleaner();
		state_visualizer();
		cleaner();
	}

}

template
<typename Type>

void SortMaster<Type>::cleaner() {

	std::cout << "\x1B[1J\x1B[H";

}

template
<typename Type>

bool SortMaster<Type>::is_sorted() {

	for (size_t i{}; i < size - 1; i++)
		if (array_to_sort[i] > array_to_sort[i + 1]) {
			return false;
		}

	return true;

}
