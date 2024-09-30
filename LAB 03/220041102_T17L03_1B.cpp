#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

#define vi vector<int>
#define vs vector<string>

class Wizerd{
    public:
        string name,house;
        int age,order;

    public:
        Wizerd(string name, int age, string house, int order){
            this->name = name;
            this->house = house;
            this->age = age;
            this->order = order;
        }
        bool operator<(const Wizerd & other)const{
            if (age==other.age) return order >other.order;
            return age < other.age;
        }
};

int main(){
    vector<Wizerd> w;
    string s,n,h;
    int a,o=0;
    while(cin>>s&&s!="X"){
        if(s=="I"){
            char dummy;
            cin.ignore();
            getline(cin,n, ',');
            cin>>a>>dummy;
            getline(cin,h);
            w.push_back(Wizerd(n,a,h,o++));
            sort(w.begin(),w.end());
        }
        else if (s=="S"){
            cin.ignore();
            if(!w.empty()){
                cout<<"Name: "<<w.back().name<<", Age: "<<w.back().age<<", House:"<<w.back().house<<endl;
                w.pop_back();
            }
            else cout<< "Voldemort Won!!!"<<endl;
        }
    }

    return 0;
}
