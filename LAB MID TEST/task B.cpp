#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*void sorting(int *array, int end){
	for(int i=1;i<end;i++){
		for(int j= i+1; j<=end; j++){
			if( array[i]<array[j]) swap(array[i],array[j]);
		}
	}
}*/


int main(){
	int t,i=1;cin>>t;
	while(t--){
		cout<<"Case "<<i++<<":"<<endl;
		stack<string> holder_urls;
		int flag = 0;
		string s,x="http://www.lightoj.com/";
		while(cin>>s && s!= "QUIT"){
			if(s==""){
				string s1;cin>>s1;
				cout<<s1<<endl;
				holder_urls.push(s1);
				flag++;
			}
			else if(s=="BACK"){
				if (!holder_urls.empty()){
					cout<<holder_urls.top()<<endl;
					holder_urls.pop();
				}
				else if(flag){
					cout<<x<<endl;
					flag=0;
				}
				else if(!flag){
					cout<<"Ignored"<<endl;
				}
			}
		}
	}
	return 0;
}