#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#define br cout<<endl
using namespace std;

int main(){
    int n;cin>>n;
    queue<int>grouo_order;
    vector<queue<int>>line(n);
    unordered_map<int,int> array_to_store_grp;
    vector<int> staying(n+1,0);
    string s1;

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        while(x--){
            int x1;cin>>x1;
            array_to_store_grp[x1]=i;
        }
    }

    cin.ignore();
    while(cin>>s1&&s1!="STOP"){
        if(s1=="ENQUEUE"){
            int x,group_ext;cin>>x;cin.ignore();
            group_ext = array_to_store_grp[x];
            if(staying[group_ext]==0){
                grouo_order.push(group_ext);
                staying[group_ext]=1;
            }
            line[group_ext-1].push(x);
        }
        else if(s1=="DEQUEUE"){
            int group_ext=grouo_order.front();
            cout<<line[group_ext-1].front()<<endl;
            line[group_ext-1].pop();
            if(line[group_ext-1].empty()){
                staying[group_ext]=0;
                grouo_order.pop();
            }
        }
    }
    return 0;
}