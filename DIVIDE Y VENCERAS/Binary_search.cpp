#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int index = binarySearch(arr, target);

    if (index != -1) {
        cout << "El objetivo " << target << " se encuentra en el índice " << index << endl;
    } else {
        cout << "El objetivo " << target << " no se encuentra en el arreglo" << endl;
    }

    return 0;
}
