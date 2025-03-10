#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define f(i,n) for(int i=1;i<=n;i++)
#define f1(i,n) for(int i=0;i<n;i++)

#define vvi vector<vector<int>>
#define vi vector<int>
#define vpis vector<pair<int,string>>

struct Node{
    int discovery,finishing, predecessor;
    char color;
};

#define mIN map<int,Node>


void DFS_visit(int u, mIN &nodes, vvi &adjency_list,vi &dfsOrdsa ,vpis &edgeTypes, int &timecount){
    nodes[u].color ='G';
    nodes[u].discovery = ++timecount;
    dfsOrdsa.push_back(u);
    for(int i: adjency_list[u]){
        if (nodes[i].color == 'W'){
            nodes[i].predecessor = u;
            edgeTypes.push_back({u*100+i,"Tree Edge"});
            DFS_visit(i,nodes,adjency_list,dfsOrdsa,edgeTypes,timecount);
        }
        else if (nodes[i].color == 'G') edgeTypes.push_back({u*100+i,"Back Edge"});
        else if (nodes[u].discovery<nodes[i].discovery)edgeTypes.push_back({u*100+i,"Forward Edge"});
        else edgeTypes.push_back({u*100+i,"Cross Edge"});
    }
    nodes[u].color = 'B';
    nodes[u].finishing = ++timecount;
}

void DFS(int v, vvi &adjency_list){
    mIN nodes;
    vi dfsOrdsa;
    vpis edgeTypes;
    int timeCounter =0;

    f(i,v)nodes[i]={0,0,-1,'W'};

    f(i,v)if (nodes[i].color=='W')DFS_visit(i, nodes, adjency_list, dfsOrdsa, edgeTypes, timeCounter);

    cout << "DFS order: ";
    for(int x:dfsOrdsa) cout<<x<<" ";
    cout<<endl<<endl;

    cout<<"Timestamps of vertex(discovery/finishiing)"<<endl;
    f(i,v) cout<< i << "(" <<nodes[i].discovery <<"/"<<nodes[i].finishing<<")"<<endl;
    cout<<endl;

    cout<< "Edge classification: "<<endl;
    for(auto it: edgeTypes){
        int u = it.first/100, v = it.first%100;
        cout<<u<< " "<<v<<": "<<it.second<<endl;
    }
    cout<<endl;
}

int main(){
    int v,e;
    cin>>v>>e;
    vvi adjency_list(v+1);
    f(i,e){
        int u,v;
        cin>>u>>v;
        adjency_list[u].push_back(v);
    }
    cout<< "Adjacency list:"<<endl;
    f(i,v){
        cout<<i<<": ";
        f1(j,adjency_list[i].size())cout<<adjency_list[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    DFS (v,adjency_list);

    return 0;
}