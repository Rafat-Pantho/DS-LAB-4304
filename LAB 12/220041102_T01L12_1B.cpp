#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

#define f(i,n) for(int i=1;i<=n;i++)
#define f1(i,n) for(int i=0;i<n;i++)
#define nlim numeric_limits<int>::max()

struct Node {
    int distance, predecessor;
    char color;
};

void BFS (int v, vector<vector<int>> &adjency_list, int s){
    map<int, Node> nodes;
    vector<int> bfsOrdrs;
    vector<pair<int, int>> bfsTre;
    queue<int> keeper;

    f(i,v)nodes[i]={nlim,-1,'W'};
    nodes[s]={0,-1,'G'};
    keeper.push(s);

    while(!keeper.empty()){
        int u=keeper.front();keeper.pop();
        bfsOrdrs.push_back(u);
        for(auto i: adjency_list[u]) if (nodes[i].color=='W'){
                nodes[i]={nodes[u].distance+1,u,'G'};
                bfsTre.push_back({u,i});
                keeper.push(i);
        }
        nodes[u].color='B';
    }

    cout << "BFS order: ";
    f1(i,bfsOrdrs.size())cout<<bfsOrdrs[i]<<" ";
    cout<<endl<<endl;

    cout<<"Distance from Source:"<<endl;
    f(i,v)if(nodes[i].distance!= nlim)cout<<i<< "(" << nodes[i].distance << ") ";
    cout<<endl<<endl;

    cout<< "Path from dource:"<<endl;
    f(i,v)if(nodes[i].distance!=nlim){
        if(nodes[i].distance!=nlim){
            vector<int> p;
            for(int n =i;n!=-1;n=nodes[n].predecessor)p.push_back(n);
            cout<<i<<": ";
            for(int j =p.size()-1;j>=0;j--){
                cout<<p[j];
                if(j>0)cout<< "->";
            }
            cout<<endl;
        }
    }

    cout <<endl;

    cout <<"Edges of BFS tree: "<<endl;
    for (auto i: bfsTre)cout<<i.first<<" "<<i.second<<endl;
    cout<<endl;
}


int main(){
    int v,e,s;
    cin>>v>>e>>s;
    vector<vector<int>> adjency_list(v+1);
    f(i,e){
        int u,v;
        cin>>u>>v;
        adjency_list[u].push_back(v);
        adjency_list[v].push_back(u);
    }
    cout<< "Adjacency list:"<<endl;
    f(i,v){
        cout<<i<<": ";
        f1(j,adjency_list[i].size())cout<<adjency_list[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    BFS(v,adjency_list,s);

    return 0;
}