#include <iostream>
using namespace std;

int partition(int *arr, int si, int ei) {
    int pivot = arr[ei];
    int i = si - 1;

    for (int j = si; j < ei; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void quick_sort(int *arr, int si, int ei) {
    // base case
    if (si >= ei) {
        return;
    }
 
    int pivotIdx = partition(arr, si, ei);

    // recursive calls for quick_sort
    quick_sort(arr, si, pivotIdx - 1);
    quick_sort(arr, pivotIdx + 1, ei);
}

// printing array
void print_array(int *arr, int n) {
    cout << "The required sorted array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array:" << endl;
    cin >> n;
    int* arr = new int[n];
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);
    print_array(arr, n);

    delete[] arr;  // free dynamically allocated memory
    return 0;
}
