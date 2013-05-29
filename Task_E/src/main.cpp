/*
 * Authored by Remo Koch
 * Public repository at https://github.com/rkoch/uzh-inf02b-a4
 */

#include <iostream>
#include <algorithm>
#include <ctime>

#define LENGTH 30000

class Sort {

public:
	void insertionSort(int arr[], int length);
	void quickSort(int arr[], int left, int right);

private:
	int partition(int a[], int left, int right);
	void exchange(int a[], int i, int j);

};

// implementation

void Sort::insertionSort(int arr[], int length) {
	for (int i = 1; i < length; i++) {
		int tmp = arr[i];
		int j = i - 1;
		while (j >= 0 && tmp < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}

void Sort::quickSort(int a[], int left, int right) {
	if (left < right) {
		int partitionIdx = partition(a, left, right);
		quickSort(a, left, partitionIdx - 1);
		quickSort(a, partitionIdx + 1, right);
	}
}

int Sort::partition(int a[], int left, int right) {
	int i = left;
	int j = right - 1;
	int pivot = a[right];

	while (i < j) {
		// find element on the left, that is bigger than pivot
		while ((a[i] <= pivot) && (i < right)) {
			i++;
		}
		// find element on the right, that is smaller than pivot
		while ((a[j] >= pivot) && (j > left)) {
			j--;
		}
		// if there was something found to exchange, do it
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	}
	if (a[i] > pivot) {
		std::swap(a[i], a[right]);
	}

	return i;
}

// Helper functions

void printArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << arr[i] << ' ' << std::flush;
	}
	std::cout << std::endl;
}

// Main

int main(int argc, char * const argv[]) {
	srand(getpid());

	std::cout << "Enter the " << LENGTH << " elements of the array" << std::endl;
	int arr_insertion[LENGTH];
	int arr_quick[LENGTH];
	for (int i = 0; i < LENGTH; i++) {
		arr_insertion[i] = arr_quick[i] = rand() % 100000;
	}
	std::cout << "All elements got inserted automatically through some random generator." << std::endl;

//	std::cout << "List before sorting: " << std::endl;
//	printArray(arr_insertion, LENGTH);

	Sort Object;

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	clock_t clock_start = clock();
	Object.insertionSort(arr_insertion, LENGTH);
	clock_t clock_stop = clock();
	std::cout << "Insertion sort took " << 1000.0 * double(clock_stop - clock_start) / CLOCKS_PER_SEC << "ms" << std::endl;
//	std::cout << "List after insertion sort: " << std::endl;
//	printArray(arr_insertion, LENGTH);

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	clock_start = clock();
	Object.quickSort(arr_quick, 0, LENGTH - 1);
	clock_stop = clock();
	std::cout << "Quick sort took " << 1000.0 * double(clock_stop - clock_start) / CLOCKS_PER_SEC << "ms" << std::endl;
//	std::cout << "List after quick sort: " << std::endl;
//	printArray(arr_quick, LENGTH);

	std::cout << std::endl;
	std::cout << "---------------------" << std::endl;
	bool correct = true;
	for (int i = 0; i < LENGTH; i++) {
		if (arr_insertion[i] != arr_quick[i]) {
			correct = false;
			break;
		}
	}
	if (correct) {
		std::cout << "Both sorting algorithms returned the same result, so we can assume everything worked correctly." << std::endl;
	} else {
		std::cout << "Sorting algorithms did not return the same result, so there must be a bug somewhere!" << std::endl;
	}

	return 0;
}

