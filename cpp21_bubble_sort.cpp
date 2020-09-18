# include <bits/stdc++.h>
using namespace std;

void swap(int* x, int* y) {  
    int temp = *x;  
    *x = *y;  
    *y = temp;
}

void bubbleSort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n-1; i++) {
    // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {  
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

  
// Function to print an array
void printArray(int arr[], int size) {  
    int i;  
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";  
    }
}  
  
int main() {  
    int arr[] = {64, 34, 67, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  