#include <bits/stdc++.h>

using namespace std;


string compare_lexico(string s1, string s2){
    for(int i=0; i<min(s1.length(), s2.length()); i++){
        if(s1[i]<s2[i]) return s1;
        else if(s1[i]>s2[i]) return s2;
    }
    if(s1.length()<=s2.length()) return s1;
    return s2;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for(int i=0; i<n; i++) cin >> a[i];
        string s; // Empty string

        for(int i=0;i<n;i++){
            s = compare_lexico(a[i]+s, s+a[i]);
        }

        cout << s << endl;
    }
}