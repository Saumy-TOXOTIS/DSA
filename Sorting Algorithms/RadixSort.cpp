#include <bits/stdc++.h>
using namespace std;

/*
Radix Sort :
Start with the least significant digit (rightmost digit).
Sort the values based on the digit in focus by first putting the values in the correct bucket based on the digit in focus, and then put them back into array in the correct order.
Move to the next digit, and sort again, like in the step above, until there are no digits left.
*/

// Stable counting sort according to digit represented by exp (1,10,100,...)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);   // output array
    int count[10] = {0};     // count array for digits 0-9

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Convert to prefix sum (to find positions)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array (stable: loop from right to left)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Main Radix Sort (LSD base-10)
void radixSort(vector<int>& arr) {
    if (arr.empty()) return;

    int mx = *max_element(arr.begin(), arr.end());

    // Do counting sort for each digit place
    for (int exp = 1; mx / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Before sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    radixSort(arr);

    cout << "After sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
