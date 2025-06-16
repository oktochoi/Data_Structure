//사용법

#include <iostream>
#include "sort.h"
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    insertionSort(arr, n);

    bubbleSort(arr, n);

    quickSort(arr, 0, n - 1);

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}
