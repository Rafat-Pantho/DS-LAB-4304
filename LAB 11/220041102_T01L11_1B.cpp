#include <iostream>
#include <vector>
using namespace std;

#define f(i,n) for (int i =1;i<=n;i++)

int main(){
    int V, E; cin>>V>>E;
    vector <vector<int>> vertix_list_storer(V+1);
    vector<vector<int>> matrix_form_storer(V+1,vector<int>(V+1,0));
    f(i,E){
        int u,v; cin>>u>>v;
        vertix_list_storer[u].push_back(v);
        vertix_list_storer[v].push_back(u);
        matrix_form_storer[u][v] = 1;
        matrix_form_storer[v][u] = 1;
    }

    cout<<"Adjacency List:\n";
    f(i,V){
        cout<<i<<": ";
        for(auto &x:vertix_list_storer[i]) cout<<x<<" ";
        cout<<endl;
    }

    cout<<"\nAdjacency Matrix:\n";
    f(i,V){
        f(j,V)cout<<matrix_form_storer[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}