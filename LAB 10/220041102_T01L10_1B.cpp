#include <iostream>
#include <vector>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)

class disjointSet{
    private:
        vector<int> parent;
    public:
        disjointSet(int n){
            parent.resize(n);
            f(i,n)parent[i] = i;

        }
        ~disjointSet(){
            parent.clear();
        }

        int find(int x){
            return parent[x]==x ? x : find(parent[x]);
        }

        void unionSet(int x, int y){
            int pos_x = find(x);
            int pos_y = find(y);
            if(pos_x != pos_y)parent[pos_y] = pos_x;
        }

        void print_dsu(){
            f(i,parent.size()) cout<<parent[i]<<" ";
            cout<<endl;
        }
};

int main(){
    int n, op;cin>>n>>op;
    disjointSet ds(n);
    ds.print_dsu();

    while(1){
        cin>>op;
        if(op == 3){
            int x,y;cin>>x>>y;
            ds.unionSet(x,y);
            ds.print_dsu();
        }
        else if(op == 2){
            int x;cin>>x;
            cout<<ds.find(x)<<endl;
        }
        else break;
    }

    return 0;
}