#include <bits/stdc++.h>
using namespace std;

//1.
int main() {
    unordered_set<int> mset;
    int x;
    int ans;
    while(cin>>x) {
        if(mset.find(2020-x)!=mset.end()) {
            ans=x*(2020-x);
        }
        mset.insert(x);
    }
    cout<<ans<<endl;
}

//2.
/*
int main() {
    unordered_set<int> mset;
    vector<int> v;
    int x;
    while(cin>>x) {
        v.push_back(x);
        mset.insert(x);
    }
    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {
            if(mset.find(2020-v[i]-v[j])!=mset.end()) {
                cout<<v[i]*v[j]*(2020-v[i]-v[j])<<endl;
            }
        }
    }
}
*/
