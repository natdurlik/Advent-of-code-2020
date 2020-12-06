#include <bits/stdc++.h>
using namespace std;


//04.12.20 2.
bool pattern1(int pos,string line,int st,int ed) {
    string sub;
    int num;
    if(pos!=string::npos) {
        sub=line.substr(pos+4);
        if(sub.length()==4||(sub.length()>4&&sub[4]==' ')) {
            sub=sub.substr(0,4);
            if(sub.find_first_not_of("0123456789")==std::string::npos) {
                num=stoi(sub);
                if(num>=st&&num<=ed) return true;
            }
        }
    }
    return false;
}
int main() {
    string line;
    int valid=0;
    bool byr=0,iyr=0,eyr=0,hgt=0,hcl=0,ecl=0,pid=0;
    while(getline(cin,line)) {
        if(line.empty()) {
            if(byr&&iyr&&eyr&&hgt&&hcl&&ecl&&pid)
                valid++;
            byr=iyr=eyr=hgt=hcl=ecl=pid=0;
        }
        else {
            string sub;
            int pos;
            int num;

            byr=byr||pattern1(line.find("byr:"),line,1920,2002);
            iyr=iyr||pattern1(line.find("iyr:"),line,2010,2020);
            eyr=eyr||pattern1(line.find("eyr:"),line,2020,2030);


            pos=line.find("hgt:");
            if(pos!=string::npos) {
                sub=line.substr(pos+4);
                if(sub.length()>=4) {
                    if(isdigit(sub[0])&&isdigit(sub[1])) {
                        if(isdigit(sub[2])) {
                            if(sub.length()==5||sub.length()>5&&sub[5]==' ') {
                                if(sub[3]=='c'&&sub[4]=='m') {
                                    num=stoi(sub.substr(0,3));
                                    if(num>=150&&num<=193) hgt=1;
                                }
                            }
                        }
                        else {
                            if(sub.length()==4||sub.length()>4&&sub[4]==' ') {
                                if(sub[2]=='i'&&sub[3]=='n') {
                                    num=stoi(sub.substr(0,2));
                                    if(num>=59&&num<=76) hgt=1;
                                }
                            }
                        }
                    }
                }
            }

            pos=line.find("hcl:");
            if(pos!=string::npos) {
                sub=line.substr(pos+4);
                if((sub.length()==7||(sub.length()>7&&sub[7]==' '))&&sub[0]=='#') {
                    sub=sub.substr(1,6);
                    if(sub.find_first_not_of("0123456789abcdef")==std::string::npos) {
                        hcl=1;
                    }
                }
            }
            pos=line.find("ecl:");
            if(pos!=string::npos) {
                sub=line.substr(pos+4);
                if(sub.length()==3||(sub.length()>3&&sub[3]==' ')) {
                    sub=sub.substr(0,3);
                    if(sub=="amb"||sub=="blu"||sub=="brn"||sub=="gry"||sub=="grn"||sub=="hzl"||sub=="oth") {
                        ecl=1;
                    }
                }
            }

            pos=line.find("pid:");
            if(pos!=string::npos) {
                sub=line.substr(pos+4);
                if(sub.length()==9||(sub.length()>9&&sub[9]==' ')) {
                    sub=sub.substr(0,9);
                    if(sub.find_first_not_of("0123456789")==std::string::npos) {
                        pid=1;
                    }
                }
            }
        }
        //cout<<byr<<" "<<iyr<<" "<<eyr<<" "<<hgt<<" "<<hcl<<" "<<ecl<<" "<<pid<<endl;
    }
    if(byr&&iyr&&eyr&&hgt&&hcl&&ecl&&pid) valid++;
    cout<<valid<<endl;
}
