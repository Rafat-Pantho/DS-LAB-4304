#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    stack<char> st;

    for(unsigned int i=0;i<s.size();i++){
        if(st.empty() || (s[i]!=st.top())) st.push(s[i]);
        else if(s[i]==st.top()) st.pop(); 
    }

    if(st.empty()) cout<<"Null"<<endl;
    else{
        stack <char> st1;
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }

        while(!st1.empty()){
            cout<<st1.top();
            st1.pop();
        }

        cout<<endl;
    }

    return 0;
}