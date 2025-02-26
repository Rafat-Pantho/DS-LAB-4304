#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define f(i,n) for (int i =0;i<n;i++)

int main(){
    int N,M;cin>>N>>M;
    vector<vector<int>> vertix_con_list(N);
    vector<int> in_deg(N,0), topological_order_list;
    queue<int> temp;
    f(i,M){
        int u,v; cin>>u>>v;
        vertix_con_list[u].push_back(v);
        in_deg[v]++;
    }

    f(i,N) if(in_deg[i] == 0) temp.push(i);

    while(!temp.empty()){
        int x= temp.front();
        temp.pop();
        topological_order_list.push_back(x);
        for(auto &i: vertix_con_list[x]){
            in_deg[i]--;
            if(in_deg[i] == 0) temp.push(i);
        }
    }

    if(topological_order_list.size() == N){
        for(auto &i: topological_order_list)cout<<i<<" ";
        cout<<endl;
    }
    else cout<< "[ ]"<<endl;

    return 0;
}