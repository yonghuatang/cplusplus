# include <bits/stdc++.h>
using namespace std;

template<typename T> void swap(T* x, T* y) {  
    const T temp = *x;  
    *x = *y;  
    *y = temp;
}


/* or pass by reference
template<typename T> void swap(T& x, T& y) {  
    const T temp = x;  
    x = y;  
    y = temp;
}
*/


template<typename T> void bubbleSort(T arr[], int size) {
    cout << "\nInput array: " << endl;
    // Print array before sort
    for (int e=0; e<size; e++) {
        cout << arr[e] << " ";
    }
    for (int i=0; i<size-1; i++) {
    // Last i elements are already sorted in place  
        for (int j=0; j<size-i-1; j++) {
            if (arr[j] > arr[j+1]) {  
                swap<T>(&arr[j], &arr[j+1]);
            }
        }
    }
}


template<typename T> void printArray(T arr[], int size) {
    cout << "\nSorted array: " << endl;  
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";  
    }
    cout << "\nDone." << endl;
}


int main() {  
    int myArray[] = {64, 34, 67, 12, 22, 11, 90, 3, 199};
    const int myArraySize = sizeof(myArray) / sizeof(myArray[0]);
    bubbleSort<int>(myArray, myArraySize);
    printArray<int>(myArray, myArraySize);

    char myArray2[] = {'e', 'y', 'l', 'l', 'g', 'x', 'o', 'i', 'n', 'm'};
    const int myArraySize2 = sizeof(myArray2) / sizeof(myArray2[0]);
    bubbleSort<char>(myArray2, myArraySize);
    printArray<char>(myArray2, myArraySize);
    return 0;
}
