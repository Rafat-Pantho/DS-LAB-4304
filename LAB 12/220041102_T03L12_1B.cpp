#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

#define f(i,n) for(int i=1;i<=n;i++)
#define f1(i,n) for(int i=0;i<n;i++)
#define msvs map<string, vector<string>>
#define qvs queue<vector<string>>
#define vs vector<string>

void findpath(msvs &map_citi_path, string src, string dst, int k){
    qvs storer;
    storer.push({src});
    while(!storer.empty()){
        vs path = storer.front();
        storer.pop();
        string l = path.back();
        if(l == dst){
            f1(i,path.size()) cout<<path[i]<< (i+1<path.size()?" ":"\n");
            return;
        }
        for(string shs: map_citi_path[l])
        if(find(path.begin(),path.end(),shs)==path.end())
        if((path.size() - 1)%k==0){
            vs np = path;
            np.push_back(shs);
            storer.push(np);
        }
    }
    cout<< "NO"<<endl;
}

int main(){
    int V,E,Q;cin>>V>>E>>Q;
    vs citis(V);
    msvs cities_map_path;

    f1(i,V){
        cin>>citis[i];
        cities_map_path[citis[i]]={};
    }
    f(i,E){
        string u,v;cin>>u>>v;
        cities_map_path[u].push_back(v);
        cities_map_path[v].push_back(u);
    }
    f(i,Q){
        string src,dst;
        int k;
        getchar();
        cin>>src>>dst>>k;
        findpath(cities_map_path,src,dst,k);
    }
    return 0;
}