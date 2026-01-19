#include <bits/stdc++.h>

using namespace std;


int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        int l, a, b;
        cin >> l >> a >> b;
        int g;
        int ans;
        if(gcd(l, b)!=1) {
            g=l/b;
            if(g==0 && b%l==0) {
                ans = a;
            }
            while(g!=0 && a+g<l){
                a+=g;
            }
            ans=a;

        }
        else ans=l-1;
        cout<<ans<<endl;
    }
}
