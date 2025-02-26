#include <iostream>
#include <vector>
#include <queue>


using namespace std;

#define f(i,n) for (int i =1;i<=n;i++)

int main(){
    int N,M,src,dest; cin>>N>>M;
    vector<vector<int>> vertix_con_list(N+1);
    vector<bool> visited(N+1,false);
    queue<int> temo;
    f(i,M){
        int a,b; cin>>a>>b;
        vertix_con_list[a].push_back(b);
    }
    cin>>src>>dest;
    temo.push(src);
    visited[src] = true;
    while(!temo.empty()){
        int x = temo.front(); temo.pop();
        for(auto &i:vertix_con_list[x]){
            if(i == dest) {
                cout<<"Yes";
                return 0;
            }
            if(!visited[i]){
                visited[i] = true;
                temo.push(i);
            }
        }
    }
    cout<<"No";
    return 0;
}