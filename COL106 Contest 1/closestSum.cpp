#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ==========================================
// IMPLEMENT YOUR SOLUTION HERE
// ==========================================
long long findClosestSum(const vector<long long>& a, long long target) {
    // Initialize with the first possible pair sum
    long long closest_sum = a[0] + a[1];
    
    // TODO: Write your logic here!
    int left = 0;
    int right = a.size() - 1;
    while (left < right) {
        long long current_sum = a[left] + a[right];
        
        
        if (abs(current_sum - target) < abs(closest_sum - target)) {
            closest_sum = current_sum;
        }
        
        if (current_sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return closest_sum;
}

// ==========================================
// BOILERPLATE I/O
// ==========================================
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int case_num = 1;

    // Read until EOF or until n = 0
    while (cin >> n && n != 0) {
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // We sort the array here so it is ready for the Two-Pointer technique
        sort(a.begin(), a.end());

        int m;
        cin >> m;

        // Print the case header exactly as the problem requires
        cout << "Case " << case_num++ << ":\n";

        // Process each of the 'm' queries
        for (int q = 0; q < m; ++q) {
            long long target;
            cin >> target;

            // Call the core function to find the closest sum
            long long result = findClosestSum(a, target);

            // Print the result in the exact format required
            cout << "Closest sum to " << target << " is " << result << ".\n";
        }
    }

    return 0;
}
