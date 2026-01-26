#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if(k==1) {
            // check if a is sorted
            bool is_sorted = true;
            for (int i = 1; i < n; ++i) {
                if (a[i] < a[i-1]) {
                    is_sorted = false;
                    break;
                }
            }
            if (is_sorted) cout << "yes" << "\n";
            else cout << "no" << "\n";
        }
        else if(k>1) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}