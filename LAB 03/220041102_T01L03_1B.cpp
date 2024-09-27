#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define br cout<<endl;

void heapify(vi & array1, int n, int i){
    int m=i,l=2*i,r=2*i+1;
    if(l<=n && array1[l-1]>array1[m-1])m=l;
    if(r<=n && array1[r-1]>array1[m-1])m=r;
    if(m!=i){
        swap(array1[i-1],array1[m-1]);
        heapify(array1,n,m);
    }
}
void Build_max_heap(vi & array1){
    int visize = array1.size();
    int i = (visize/2);
    while (i)heapify(array1,visize,i--);
}
void Heap_sort(vi & array1){
    int visize = array1.size();
    Build_max_heap(array1);
    for(int i= visize;i>0;i--){
        swap(array1[0],array1[i-1]);
        heapify(array1,i-1,1);
    }
}

int main(){
    vi a;
    while(true){
        int x;cin >> x;
        if (x==-1)break;
        a.push_back(x);
    }
    br;

    Build_max_heap(a);
    cout<<"Max Heap: ";
    for(auto x:a)cout<<x<<" ";
    br;

    Heap_sort(a);
    cout<<"Sorted: ";
    for(int i = a.size()-1;i>=0;)cout<<a[i--]<<" ";
    br;

    return 0;
}