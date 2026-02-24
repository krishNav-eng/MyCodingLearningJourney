#include <bits/stdc++.h>
using namespace std;

vector<int> findPermutation(int N, string S) {
    int low=1, high=N;
    vector<int> ans;
    for(auto it : S) {
        if(it=='I'){
            ans.push_back(low++);
        } else {
            ans.push_back(high--);
        }
    }
    while(low<=high){
        ans.push_back(low++);
    }
    return ans;
}

int main() {
    vector<int> ans=findPermutation(5, "DIDD");
    for(int i:ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}