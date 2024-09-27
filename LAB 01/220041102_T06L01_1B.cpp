#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int main(){

    int t;cin >> t;
    cin.ignore();
    while(t--){
        string s1;
        getline(cin,s1);
        stack<char> math_to_done_on;

        bool flag = true;

        for(unsigned int i=0;i<s1.size();i++){
            if(!isdigit(s1[i])){
                if((s1[i]=='(' || s1[i]=='[' || s1[i]=='{'))math_to_done_on.push(s1[i]);
                else if (s1[i]==')' || s1[i] == '}' || s1[i] ==']'){
                    if (math_to_done_on.empty()){
                        flag = false;
                        break;
                    }
                    if((s1[i]==')' && math_to_done_on.top()=='(') || (s1[i] == '}' && math_to_done_on.top() == '{') || (s1[i] == ']' && math_to_done_on.top() == '[')) math_to_done_on.pop();
                    else {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if(!math_to_done_on.empty())flag = false;

        cout<< ((flag)? "Yes":"No")<<endl;
    }

    return 0;
}