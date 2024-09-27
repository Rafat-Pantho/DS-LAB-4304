#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void swap(int &a , int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int n; cin>>n;
    stack<int> st;
    vector<int> array_1(n+1);
    vector<int> array_2(n+1,0);
    array_1[0]=0;

    for(int i=1;i<=n;i++)cin>>array_1[i];

    for(int i=1;i<=n;i++){
        if( (i==1 && array_1[i]>array_1[i+1]) || ( array_1[i]>array_1[i+1] && array_1[i-1]>array_1[i]) || i<array_1[i] ){
            if(i<array_1[i] && i!=n && array_1[i]-array_1[i+1]==1)swap(array_1[i],array_1[i+1]);
            else{
                st.push(array_1[i]);
                array_1[i]=0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(array_1[i]!=0){
            array_2[array_1[i]] = array_1[i];
        }
    }

    for(int i=1;i<=n;i++) if(array_2[i]==0 && i == st.top())st.pop();

    cout<< (st.empty()? "Yes": "No") << endl;

    return 0;
}