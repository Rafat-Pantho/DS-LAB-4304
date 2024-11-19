#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

void tls(string &s){
    transform(lower.begin(),lower.end(),lower.begin(),::tolower);
}

string rP(string s){
    string a;
    for(auto c:s)if(isalnum(c)||c==' ')a+=c;
    return a;
}

int main(){
    string s;
    getline(cin,s);
    // tls(s);
    string s1=rP(s);

    unordered_map<string,int> m;
    isstringstream stream(s1);
    string container;
    while(stream>>container)m[container]++;
    bool flag = false;
    for(auto i:m){
        if(i.second>1){
            cout<<i.first<<" "<<i.second<<endl;
            flag = true;
        }
    }
    if(!flag)cout<<"No multiple occurance"<<endl;
}