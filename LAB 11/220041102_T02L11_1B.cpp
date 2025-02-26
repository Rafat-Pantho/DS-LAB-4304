#include <iostream>
#include <vector>

using namespace std;

#define f(i,n) for (int i =1;i<=n;i++)

int main(){
    int V, E, flag = 1,k; cin>>V>>E;
    vector<int> edge_count_in_vertix_no(V+1);
    f(i,E){
        int u,v; cin>>u>>v;
        edge_count_in_vertix_no[u]++;
        edge_count_in_vertix_no[v]++; 
    }
    k = edge_count_in_vertix_no[1];
    f(i,V) if(edge_count_in_vertix_no[i] != k) flag = 0;
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
