#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j); 
        }
    }

    swap(arr, i + 1, high);  
    return (i + 1);  
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int size = arr.size();
    cout << "Arreglo original: ";
    printArray(arr);
    quickSort(arr, 0, size - 1);
    cout << "Arreglo ordenado: ";
    printArray(arr);

    return 0;
}
