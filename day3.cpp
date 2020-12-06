#include <bits/stdc++.h>
using namespace std;

//03.12.20 1,2
int main() {
    string line;
    int counter=0;
    const int n=31;
    array<bool,n> tree;
    int pos=3;
    //cout<<line.length();
    getline(cin,line);
    while(getline(cin,line)) {
        for(int i=0;i<n;i++) {
            if(line[i]=='#') tree[i]=1;
            else tree[i]=0;
        }
        counter+=tree[pos];
        pos+=3;
        pos%=31;
    }
    cout<<counter<<endl;
}

