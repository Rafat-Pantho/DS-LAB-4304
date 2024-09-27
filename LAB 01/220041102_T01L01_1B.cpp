#include<iostream>
using namespace std;

//creating stack class

class stack{
    public:
        int last;
        int capacity;
        int *arr;

    public:
        stack(int capacity_given_by_user){
            capacity = capacity_given_by_user;
            last=-1;
            arr = new int [capacity_given_by_user];
        }

        void push(int z){
            if(last==capacity-1){
                cout<<"Overflow"<<endl;
                return;
            }
            arr[++last]=z;
        }

        int pop(){
            if (last==-1){
                cout<<"Underflow"<<endl;
                return -1;
            }
            return arr[last--];
        }

        bool isEmpty(){
            if(last==-1)return true;
            return false;
        }

        bool isFull(){
            if(last==capacity-1)return true;
            return false;
        }

        int size(){
            return last+1;
        }

        int top(){
            return arr[last];
        }

        ~stack(){
            delete []arr;
        }
};


int main(){
    int N;
    cin>>N;
    stack s(N);
    while(1){
        int x;cin>>x;
        if(x==-1)break;
        switch (x){
            case 1:
                int y;cin>>y;
                s.push(y);
                break;

            case 2:
                cout<<s.pop()<<endl;
                break;

            case 3:
                (s.isEmpty())?cout<<"True"<<endl:cout<<"False"<<endl;
                break;
            
            case 4:
                (s.isFull()) ? cout << "True" << endl : cout << "False" << endl;
                break;

            case 5:
                cout<<s.size()<<endl;
                break;

            case 6:
                cout<<s.top()<<endl;
                break;

            default:
                break;
        }
    }
    return 0;
}