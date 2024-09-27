#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        if(s.empty()) break;
        string s1,s2;
        int size_of_s = s.size();
        bool flag = false;
        for(int i=0; i<size_of_s;i++){
            if(s[i]=='[')flag = true;
            if(s[i]==']')flag = false;
            if(s[i]!='['&&s[i]!=']'){
                if(flag) s1.push_back(s[i]);
                else s2.push_back(s[i]);
            }
        }
        cout<<s1<<s2<<endl;
    }
    return 0;
}