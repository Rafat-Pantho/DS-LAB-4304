#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#define vi vector<int>
#define qi queue<int>
#define si stack<int>

int main(){
    int n;cin>>n;
    qi students;
    vi dishes_in(n);
    si dishes;

    for(int i=0;i<n;i++){
        int x;cin>>x;
        students.push(x);
    }

    for (int i=0;i<n;)cin>>dishes_in[i++];
    for(int i=n-1;i>=0;)dishes.push(dishes_in[i--]);

    unsigned int diff=0;
    bool enough = false;

    while(!enough && !students.empty()){
        if(students.front()==dishes.top()){
            students.pop();
            dishes.pop();
            diff=0;
        }
        else{
            diff++;
            students.push(students.front());
            students.pop();
        }

        if(diff==students.size())enough=true;
    }
    
    cout<<students.size()<<endl;

    return 0;
}