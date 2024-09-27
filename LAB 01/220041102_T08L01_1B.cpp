#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

bool is_pranthesis (char c) {
    return c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
}

int main(){
    int t; cin>>t;
    cin.ignore();
    stack<char> s;
    bool flag = true;

    while(t--){
        string s1;
        getline(cin,s1);

        for(unsigned int i=0;i<s1.size();i++){
            if(is_pranthesis(s1[i])){
                if((s1[i]=='(' || s1[i]=='[' || s1[i]=='{'))s.push(s1[i]);
                else if (s1[i]==')' || s1[i] == '}' || s1[i] ==']'){
                    if (s.empty()){
                        flag = false;
                        break;
                    }
                    if((s1[i]==')' && s.top()=='(') || (s1[i] == '}' && s.top() == '{') || (s1[i] == ']' && s.top() == '[')) s.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    if(!s.empty())flag = false;
    cout<< (flag? "No Errors":"Error") <<endl;

    return 0;
}