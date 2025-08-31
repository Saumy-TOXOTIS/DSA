#include <bits/stdc++.h>
using namespace std;

/*
Bucket Sort:
1. Divide the input array into several buckets.
2. Sort each bucket individually (using a different sorting algorithm or recursively applying the bucket sort).
3. Concatenate all sorted buckets into the final output array.
*/

void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Find min and max
    int mn = *min_element(arr.begin(), arr.end());
    int mx = *max_element(arr.begin(), arr.end());

    int range = mx - mn + 1;

    // Choose number of buckets ~ sqrt(n)
    int k = max(1, (int)sqrt(n));

    vector<vector<int>> buckets(k);

    // 1) Put numbers into buckets
    for (int x : arr) {
        int idx = (int)((long long)(x - mn) * k / range);
        if (idx == k) idx = k - 1;  // clamp max
        buckets[idx].push_back(x);
    }

    // 2) Sort each bucket
    for (int i = 0; i < k; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 3) Concatenate back
    int idx = 0;
    for (int i = 0; i < k; i++) {
        for (int x : buckets[i]) {
            arr[idx++] = x;
        }
    }
}

int main() {
    vector<int> arr = {42, 32, 33, 52, 37, 47, 51};

    cout << "Before sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    bucketSort(arr);

    cout << "After sorting: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
