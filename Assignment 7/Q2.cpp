#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start, maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }
        if (minIndex != start) {
            swap(arr[start], arr[minIndex]);
            if (maxIndex == start) 
                maxIndex = minIndex; 
        }
        if (maxIndex != end)
            swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    improvedSelectionSort(arr, n);
    cout << "Sorted array:";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
