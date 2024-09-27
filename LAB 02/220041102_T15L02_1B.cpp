#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;cin>>n;
    deque<int> a;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }

    char ch = 'd';

    while (a.size()>1){
        if(ch == 'd'){
            a.push_back(a.front());
            a.pop_front();
            a.pop_front();
            ch = 'i';
        }
        else{
            a.push_back(a.front());
            a.pop_front();
            a.push_back(a.front());
            a.pop_front();
            a.pop_front();
            ch = 'd';
        }
    }

    cout<< (ch=='i' ? "Daiyan ":"Ishraq ")<<a.front()<<endl;

    return 0;
}