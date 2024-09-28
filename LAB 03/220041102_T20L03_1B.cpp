#include <iostream>
#include <vector>

using namespace std;

#define vi vector<int>
#define br cout<<endl;
#define f(i,n) for(int i=0;i<n;i++)
#define f1(j,i,n) for(int j=i;j<n;j++)

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
    while (i) heapify(array1,visize,i--);
}
void Heap_sort(vi & array1){
    int visize = array1.size();
    Build_max_heap(array1);
    for(int i= visize;i>0;i--){
        swap(array1[0],array1[i-1]);
        heapify(array1,i-1,1);
    }
}
int Heap_Maximum(vi array1){
    return array1[0];
}
int Heap_extract_max(vi & array1){
    int x=array1[0];
    swap(array1[0],array1[array1.size()-1]);
    array1.pop_back();
    Build_max_heap(array1);
    return x;
}
void Max_heap_insert(int x, vi & array1){
    array1.push_back(x);
    Build_max_heap(array1);
}
void Heap_decrease_key(int i, int k, vi & array1){
    array1[i-1]-=k;
    Build_max_heap(array1);
}
void Heap_increase_key(int i, int k, vi & array1){
    array1[i-1]+=k;
    Build_max_heap(array1);
}

int main(){
    int n,k;cin>>n;
    string d;
    vi a(n),a1;
    f(i,n){
        if(i!=n-1)cin>>a[i]>>d;
        else cin>>a[i];
    }
    cin>>k;
    f(i,n){
        int sum =0;
        f1(j,i,n){
            sum+=a[j];
            a1.push_back(sum);
        }
    }
    Heap_sort(a1);
    cout<<a1[a1.size()-k]<<endl;
    return 0;
}