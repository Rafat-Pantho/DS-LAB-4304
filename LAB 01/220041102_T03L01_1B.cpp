#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<int> array_1;
    while(1){
        int n;cin>>n;
        if(n==-1)break;
        array_1.push_back(n);
    }

    int n; cin>>n;
    stack<int> array_3;
    vector<int> array_2(n + 1, 0);

    for(unsigned int i=0;i<array_1.size();i++){
        array_2[array_1[i]]=1;
    }

    for(int i=1;i<=n;i++){
        if(array_2[i]==1){
            cout<<"Push ";
            array_3.push(i);
        }
        else{
            cout<<"Push Pop ";
            array_3.push(i);
            array_3.pop();
        }
    }

    cout<<endl;
    return 0;
}