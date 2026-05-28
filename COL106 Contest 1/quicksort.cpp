#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// IMPLEMENT YOUR SOLUTION HERE
// ==========================================

long long countAndMerge(vector<int>& arr, int l, int m, int r) {
    long long n1 = m - l + 1, n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    long long res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      

        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

long long countInv(vector<int>& arr, int l, int r){
    long long res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

long long inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}

long long solve(vector<int>& A) {
    long long swaps = 0;
    
    // TODO: Write your logic to count the minimum number of adjacent swaps.
    swaps = inversionCount(A);
    return swaps;
}

// ==========================================
// BOILERPLATE I/O
// ==========================================
int main() {
    // Fast I/O is absolutely mandatory for N = 500,000
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    // The problem states input is terminated when n = 0
    while (cin >> n && n != 0) {
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        // Call the core function and print the result
        cout << solve(A) << "\n";
    }

    return 0;
}
