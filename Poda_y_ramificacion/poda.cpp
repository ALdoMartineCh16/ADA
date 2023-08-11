#include <bits/stdc++.h>

using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lengths(n, 1); // Inicialmente, cada posición es una secuencia de longitud 1

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && lengths[i] < lengths[j] + 1) {
                lengths[i] = lengths[j] + 1;
            }
        }
    }

    int maxLength = 0, endIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
            endIndex = i;
        }
    }

    vector<int> lis;
    while (maxLength > 0) {
        lis.insert(lis.begin(), nums[endIndex]);
        --maxLength;
        --endIndex;
        while (endIndex >= 0 && lengths[endIndex] != maxLength) {
            --endIndex;
        }
    }

    return lis;
}

int main() {
    vector<int> nums = {11, 17, 5, 8, 6, 4, 7, 12, 3};

    vector<int> lis = longestIncreasingSubsequence(nums);

    cout << "Secuencia creciente de máxima longitud: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
