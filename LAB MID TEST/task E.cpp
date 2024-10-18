#include <iostream>
#include <string>
#include <vector>
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
	int count =0;
	int x;cin>>x;
	vector<int> array_1;
	string s;
	for(int i=1;i<=x;){
		cin>>s;
		if(s=="add"){
			int a;cin>>a;
			array_1.push_back(a);
		}
		else if(s=="remove"){
			if (i==array_1[array_1.size()-1]) array_1.pop_back();
			else{
				sort(array_1.begin(),array_1.end(),greater<int>());
				count++;
				array_1.pop_back();
			}
			i++;
		}
	}
	cout<<count<<endl;

	return 0;
}