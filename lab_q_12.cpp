//kth largsest or smallest 
#include <bits/stdc++.h>
using namespace std;

// Partition function 
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return i;
}

// Quickselect function
int quickSelect(vector<int> &arr, int low, int high, int k) {
    if (low <= high) {

        int pi = partition(arr, low, high);

        int rank = pi - low + 1;

        if (rank == k)
            return arr[pi];

        else if (k < rank)
            return quickSelect(arr, low, pi - 1, k);

        else
            return quickSelect(arr, pi + 1, high, k - rank);
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if (k < 1 || k > n) {
            cout << "not present\n";
            continue;
        }

        int ans = quickSelect(arr, 0, n - 1, k);
        cout << ans << "\n";
    }

    return 0;
}
