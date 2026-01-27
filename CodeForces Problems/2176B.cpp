#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c = 0, m = 0;
        for (int i = 0; i < 2*n; i++) {
            if (s[i % n] == '0') {
                c++;
            }
            else {
                m = max(m, c);
                c = 0;
            }
        }
        cout << m << endl;

    }


}