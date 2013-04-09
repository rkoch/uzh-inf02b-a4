#include <iostream>

#define LENGTH 10
class Sort
{
public:
  void insertionSort (int arr[], int length);
  void quickSort (int arr[], int left, int right);
private:
  int partition (int a[], int left, int right);
  void exchange (int a[], int i, int j);
};

void
Sort::insertionSort (int arr[], int length)
{
	// TODO complete
}

void
Sort::quickSort (int a[], int left, int right)
{
	// TODO complete
}

int
main (int argc, char *const argv[])
{

  std::cout << "Enter the " << LENGTH << " elements of the array" << std::
    endl;
  int arr[LENGTH];
  for (int i = 0; i < LENGTH; i++)
    {
      std::cin >> arr[i];
    }
  Sort Object;
  // Each of the following should work
  // Object.insertionSort (arr, LENGTH);
  // Object.quickSort (arr, 0, LENGTH-1);

  std::cout << "Sorted list:" << std::endl;
  for (int i = 0; i < LENGTH; i++)
    {
      std::cout << arr[i] << std::endl;
    }

  return 0;
}

