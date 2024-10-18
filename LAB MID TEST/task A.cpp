#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
	int T,i=1;cin>>T;
	while(T--){
		cout<<"Case "<<i<<":"<<endl;i++;
		int n,m,sst=0;cin>>n>>m;

		deque<int> s(n);
		while(m--){
			
			string s1;
			cin>>s1;
			if(s1=="pushLeft"){
				int x;cin>>x;
				if(sst==n){
					cout<<"The queue is full"<<endl;
					continue;
				}
				cout<<"Pushed in left: "<<x<<endl;
				s.push_front(x);
				sst++;
			}
			else if(s1=="pushRight"){
				int x;cin>>x;
				if(sst==n){
					cout<<"The queue is full"<<endl;
					continue;
				}
				cout<<"Pushed in right: "<<x<<endl;
				s.push_back(x);
				sst++;
			}
			else if(s1=="popLeft"){
				if(sst==0){
					cout<<"The queue is empty"<<endl;
					continue;
				}
				cout<<"Popped from left: "<<s.front()<<endl;
				s.pop_front();
				sst--;
			}
			else if(s1=="popRight"){
				if(sst==0){
					cout<<"The queue is empty"<<endl;
					continue;
				}
				cout<<"Popped from right: "<<s.back()<<endl;
				s.pop_back();
				sst--;
			}
		}
	}

	return 0;
}