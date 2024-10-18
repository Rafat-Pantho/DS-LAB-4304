#include <iostream>
#include <string>
#include <deque>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int n,m;cin>>n>>m;
		deque<int> s(n);
		while(m--){
			string s1;
			cin>>s1;
			if(s1=="pushLeft"){
				int x;cin>>x;
				if(s.fUll()){
					cout<<"The queue is full"<<endl;
					continue;
				}
				cout<<"Pushed in left: "<<x<<endl;
				s.push_front(x);
			}
			else if(s1=="pushRight"){
				int x;cin>>x;
				if(s.fUll()){
					cout<<"The queue is full"<<endl;
					continue;
				}
				cout<<"Pushed in right: "<<x<<endl;
				s.push_back(x);
			}
			else if(s1=="popLeft"){
				if(s.empty()){
					cout<<"The queue is empty"<<endl;
					continue;
				}
				cout<<"Popped from Left: "<<s.front()<<endl;
				s.pop_front();
			}
			else if(s1=="popRight"){
				if(s.empty()){
					cout<<"The queue is empty"<<endl;
					continue;
				}
				cout<<"Popped from Right: "<<s.back()<<endl;
				s.pop_back();

			}
		}
	}

	return 0;
}