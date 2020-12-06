#include <bits/stdc++.h>
using namespace std;

//02.12.20 1.
bool is_valid(string line) {
    int mini,maxi;
    char delim1='-';
    char delim2=' ';
    string num=line.substr(0,line.find(delim1));
    mini=stoi(num);
    num=line.substr(line.find(delim1)+1,line.find(delim2));
    maxi=stoi(num);
    line=line.substr(line.find(delim2));
    char c=line[1];
    line=line.substr(4);
    int counter=0;
    for(int i=0;i<line.length();i++)
        if(line[i]==c) counter++;
    if(counter>=mini&&counter<=maxi) return true;
    return false;
}
int main() {
    string line;
    int counter=0;
    while(getline(cin,line))
        counter+=is_valid(line);
    cout<<counter<<endl;
}

//2
/*
bool is_valid(string line) {
    int mini=stoi(line.substr(0,line.find('-')))-1;
    int maxi=stoi(line.substr(line.find('-')+1,line.find(' ')))-1;
    line=line.substr(line.find(' '));
    char c=line[1];
    line=line.substr(4);

    if(!(line[mini]==c&&line[maxi]==c)&&!(line[mini]!=c&&line[maxi]!=c)) return true;
    return false;
}

int main() {
    string line;
    int counter=0;
    while(getline(cin,line))
        counter+=is_valid(line);
    cout<<counter<<endl;
}

*/
