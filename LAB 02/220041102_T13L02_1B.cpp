#include<iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin>>n && n!=0){
        queue<int> q;
        int n1=n;
        for(int i=1;i<=n;i++)q.push(i);
        cout<<"Discarded Cards:";
        while(n1-- >1){
            if(n1!=n-1)cout<<",";
            cout<<" "<<q.front();
            q.pop();
            q.push(q.front());
            q.pop();
        }
        cout<<endl<<"Remaining card: "<<q.front()<<endl;
    }

    return 0;
}