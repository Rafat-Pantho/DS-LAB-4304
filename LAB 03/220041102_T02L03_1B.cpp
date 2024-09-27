#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define br cout<<endl;

void heapify(vi & array1, int n, int i){
    int m=i,l=2*i,r=2*i+1;
    if(l<=n && array1[l-1]<array1[m-1])m=l;
    if(r<=n && array1[r-1]<array1[m-1])m=r;
    if(m!=i){
        swap(array1[i-1],array1[m-1]);
        heapify(array1,n,m);
    }
}
void Build_min_heap(vi & array1){
    int visize = array1.size();
    int i = (visize/2);
    while (i) heapify(array1,visize,i--);
}
void Heap_sort(vi & array1){
    int visize = array1.size();
    Build_min_heap(array1);
    for(int i= visize;i>0;i--){
        swap(array1[0],array1[i-1]);
        heapify(array1,i-1,1);
    }
}
int Heap_Minimim(vi array1){
    return array1[0];
}
int Heap_extract_min(vi & array1){
    int x=array1[0];
    swap(array1[0],array1[array1.size()-1]);
    array1.pop_back();
    Build_min_heap(array1);
    return x;
}
void Min_heap_insert(int x, vi & array1){
    array1.push_back(x);
    Build_min_heap(array1);
}
void Heap_decrease_key(int i, int k, vi & array1){
    array1[i-1]-=k;
    Build_min_heap(array1);
}
void Heap_increase_key(int i, int k, vi & array1){
    array1[i-1]+=k;
    Build_min_heap(array1);
}
int main(){
    vi a;
    while(true){
        int x;cin >> x;
        if (x==-1)break;
        a.push_back(x);
    }
    br;

    Build_min_heap(a);
    cout<<"Min Heap: ";
    for(auto x:a)cout<<x<<" ";
    br;br;

    int x;
    while(cin>>x){
        switch (x){
            case 1:
                cout<<Heap_Minimim(a)<<endl;
                break;
            case 2:
                cout <<Heap_extract_min(a)<<endl;
                break;
            case 3:
                int y;cin>>y;
                Min_heap_insert(y,a);
                break;
            case 4:
                int i,k;cin>>i>>k;
                Heap_decrease_key(i,k,a);
                break;
            case 5:
                int j,l;cin>>j>>l;
                Heap_increase_key(j,l,a);
                break;
        }
        for(auto x:a)cout<<x<<" ";br;
    }

    return 0;
}