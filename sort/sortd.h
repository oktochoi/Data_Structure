#ifndef SORTLIB_DESC_H
#define SORTLIB_DESC_H

#include <iostream>
using namespace std;

// ✅ Selection Sort (내림차순)
void selectionSortDesc(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for(int j = i + 1; j < n; j++)
            if(arr[j] > arr[maxIdx]) maxIdx = j;
        swap(arr[i], arr[maxIdx]);
    }
}

// ✅ Insertion Sort (내림차순)
void insertionSortDesc(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ✅ Bubble Sort (내림차순)
void bubbleSortDesc(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// ✅ Quick Sort (내림차순)
void quickSortDesc(int arr[], int left, int right) {
    if(left >= right) return;
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(arr[j] > pivot)  // 내림차순
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[right]);
    quickSortDesc(arr, left, i);
    quickSortDesc(arr, i + 2, right);
}

// ✅ Merge Sort (내림차순)
void mergeDesc(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] >= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortDesc(int arr[], int left, int right) {
    if(left >= right) return;
    int mid = (left + right) / 2;
    mergeSortDesc(arr, left, mid);
    mergeSortDesc(arr, mid + 1, right);
    mergeDesc(arr, left, mid, right);
}

#endif
