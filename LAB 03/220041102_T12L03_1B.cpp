#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define vi vector<int>
#define gi greater<int>

int main(){
    priority_queue<int, vi, gi> a;
    int x;
    while(cin>>x && x!=-1)a.push(x);

    int cost =0;
    while(a.size()>1){
        int x = a.top();a.pop();
        int y = a.top();a.pop();
        cost+=x+y;
        a.push(x+y);
    }

    cout<<cost<<endl;

    return 0;
}