#include <bits/stdc++.h>
using namespace std;

//06.12.20
//1
int main() {
    string line;
    int sum=0;
    array<bool,26> let;
    let.fill(0);
    while(getline(cin,line)) {
        if(line.empty()) {
            for(int i=0;i<26;i++) sum+=let[i];
            let.fill(0);
        }
        for(int i=0;i<line.length();i++) {
            let[line[i]-'a']=1;
        }
    }
    for(int i=0;i<26;i++) sum+=let[i];
    cout<<sum<<endl;
}

//2
/*
int main() {
    string line;
    int sum=0;
    array<int,26> let;
    let.fill(0);
    int group=0;
    while(getline(cin,line)) {
        if(line.empty()) {
            for(int i=0;i<26;i++) sum+=let[i]==group;
            let.fill(0);
            group=0;
        }
        else {
            group++;
            for(int i=0;i<line.length();i++) {
                let[line[i]-'a']++;
            }
        }
    }
    for(int i=0;i<26;i++) sum+=let[i]==group;
    cout<<sum<<endl;
}
*/