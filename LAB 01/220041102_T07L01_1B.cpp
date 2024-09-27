#include <iostream>
#include <stack>
#include <cctype> 
#include <string>

using namespace std;

int calc(const string& str2) {
    stack<int> s;
    for (char c : str2) {
        if (isdigit(c)) s.push(c - '0');  
        else {
            int val1 = s.top();s.pop();
            int val2 = s.top();s.pop();
            switch (c) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
            }
        }
    }
    return s.top();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1;
        cin >> str1;
        cout << calc(str1) << endl;
    }
    return 0;
}
