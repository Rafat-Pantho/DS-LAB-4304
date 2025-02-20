#include <iostream>
#include <vector>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)
#define f1(i,n,a) for(int i=a;i<n;i++)

class disjointset{
    private:
        vector<int> parent, rank;
    public:
        disjointset(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            f(i,n+1) parent[i] = i;
        }
        ~disjointset(){
            parent.clear();
            rank.clear();
        }
        int find(int x){
            return (parent[x]!=x)?parent[x]=find(parent[x]):parent[x];
        }
        bool unionSet(int x, int y){
            int rut_x = find(x), rut_y = find(y);
            if (rut_x==rut_y) return false;
            if (rank[rut_x]>rank[rut_y])parent[rut_y]= rut_x;
            else if (rank[rut_x]<rank[rut_y])parent[rut_x]=rut_y;
            else {
                parent[rut_y]=rut_x;
                rank[rut_x]++;
            }
            return true;
        }
};

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> edges;
    disjointset ds(n);
    f1(i,n,1){
        int a,b;cin>>a>>b;
        if (!ds.unionSet(a,b))edges.push_back({a,b});
    }
    vector<pair<int,int>> new_edges;
    vector<int> component_roots;

    f1(i,n+1,1) if (ds.find(i)==i)component_roots.push_back(i);
    f1(i,component_roots.size(),1)new_edges.push_back({component_roots[i-1],component_roots[i]});
    cout << new_edges.size()<<endl;
    
    f(i,new_edges.size()) cout<<edges[i].first<<" "<<edges[i].second <<"\t"<<new_edges[i].first<<" "<<new_edges[i].second<<endl;

    return 0;
}