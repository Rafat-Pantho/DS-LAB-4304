#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<int> array_1;
    stack<int> array_2;
    while(1){
        int n;cin>>n;
        if(n==-1)break;
        array_1.push_back(n);
    }

    int size_arr_1= array_1.size(); 

    for(unsigned int i=0;i<size_arr_1-1;i++){
        for(unsigned int j=i+1;j<size_arr_1;j++){
            if(array_1[i]<array_1[j]){
                array_2.push(array_1[j]);
                cout<< array_1[j]<<" ";
                break;
            }
            if (j == size_arr_1 - 1 && array_1[i] > array_1[j]){
                cout<<"-1 ";
                array_2.push(-1);
            }
        }
    }

    cout<<"-1 "<<endl;
    array_2.push(-1);

    return 0;
}