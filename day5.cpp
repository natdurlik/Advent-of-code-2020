#include <bits/stdc++.h>
using namespace std;


//05.12.20 1&2
int decode(string line) {
    int x=0;
    for(int i=0;i<7;i++) {
        x<<=1;
        x+=(line[i]=='B');
    }
    int y=0;
    for(int i=7;i<10;i++) {
        y<<=1;
        y+=(line[i]=='R');
    }
    return x*8+y;
}
int main() {
    string line;
    int maxi=0;
    //int sum=0;
    int d;
    vector<bool> a(991,0);
    while(getline(cin,line)) {
        d=decode(line);
        maxi=max(maxi,decode(line));
        a[d]=1;
    }
    cout<<maxi<<endl;
    for(int i=1;i<990;i++) {
        if(!a[i]&&a[i-1]) {
            cout<<i<<endl;
            break;
        }
    }
}
