#include <iostream>
#include <vector>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)
#define wh while(1)

class disjointSet{
    private:
        vector<int> parent, rank;
    
    public:
        disjointSet(int n){
            parent.resize(n);
            rank.resize(n);
            f(i,n) parent[i] = i;
        }

        ~disjointSet(){
            parent.clear();
            rank.clear();
        }

        int find(int x){
            return (parent[x]!=x)?parent[x]=find(parent[x]):parent[x];
        }

        void unionSet(int x, int y){
            int rut_x = find(x), rut_y = find(y);
            if(rut_x != rut_y){
                if (rank[rut_x]>rank[rut_y])parent[rut_y] = parent [rut_x];
                else if (rank[rut_x]<rank[rut_y])parent[rut_x] = parent[rut_y];
                else{
                    parent[rut_x] = rut_y;
                    rank[rut_y]++;
                }
            }
        }

        void print_dsu(){
            f(i, parent.size()) cout << parent[i] << "(" << rank[i] << ") ";
            cout << endl;
        }
};

int main(){
    int n, op;cin>>n>>op;
    disjointSet ds(n);
    ds.print_dsu();

    wh{
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
        else if (op == 4){
            ds.print_dsu();
            break;
        }
    }
}