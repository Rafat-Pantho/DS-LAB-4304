#include <iostream>
#include <stack>
#include <string.h>

using namespace std;
int main(){
    int t;cin>>t;
    cin.ignore();
    while (t--){
        stack<char> s;
        string str;
        getline(cin,str);
        for(unsigned int i=0;i<str.size();i++)s.push(str[i]);
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}