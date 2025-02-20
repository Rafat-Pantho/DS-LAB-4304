#include <iostream>
#include <vector>

using namespace std;

#define f(i,n) for(int i = 0; i < n; i++)
#define wh while(1)

class disjointset{
    private:
        vector<int> parent, size;
        int comp_count,larg_comp;
    
    public:
        disjointset(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            f(i,n+1) parent[i] = i;
            comp_count = n;
            larg_comp = 1;
        }
        ~disjointset(){
            parent.clear();
            size.clear();
        }
        int find(int x){
            return (parent[x]!=x)?parent[x]=find(parent[x]):parent[x];
        }
        void unionSet(int x, int y){
            int rut_x = find(x), rut_y = find(y);
            if(rut_x != rut_y){
                if(size[rut_x]>size[rut_y])swap(rut_x,rut_y);
                parent[rut_x] = rut_y;
                size[rut_y] += size[rut_x];
                size[rut_x] = 0;
                comp_count--;
                larg_comp = (larg_comp>size[rut_y])?larg_comp:size[rut_y];
            }
        }

        int getCompCount(){
            return comp_count;
        }
        int getLargestComp(){
            return larg_comp;
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    disjointset ds(n);

    while(m--) {
        int a, b;
        cin >> a >> b;
        ds.unionSet(a, b);
        cout << ds.getCompCount() << " " << ds.getLargestComp() << endl;
    }

    return 0;
}