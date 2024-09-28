#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

#define vi vector<int>
#define f(i,n) for (int i=0;i<n;i++)

int main(){
    int n;cin>>n;
    vi a(n);
    f(i,n) cin>>a[i];
    f(i,n){
        if(i<2){
            cout<<"-1"<<endl;
            continue;
        }
        vi a1(a.begin(),a.begin()+i+1);
        sort(a1.rbegin(),a1.rend());
        cout<<a1[0]*a1[1]*a1[2]<<endl;
    }

    return 0;
}