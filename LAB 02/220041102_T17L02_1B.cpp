#include <iostream>
#include <queue>

using namespace std;

class Stack_usking_q{
    private:
        queue<int> q1,q2;
        int size_cur, capacity;

    public:
        Stack_usking_q(int s){
            size_cur=0;
            capacity =s;
        }
        ~Stack_usking_q() {}

        void push(int x){
            if(size_cur == capacity){
                cout<<"Overflow!!"<<endl;
                printStack();
                return;
            }

            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            size_cur++;

            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            printStack();
        }

        void pop(){
            if(size_cur == 0){
                cout<<"Underflow!!"<<endl;
                return;
            }
            q1.pop();
            size_cur--;
            printStack();
        }
        int top(){
            return q1.front();
        }

        bool isEmpty(){
            return size_cur == 0;
        }

        bool isFull(){
            return size_cur == capacity;
        }

        int size(){
            return size_cur;
        }

        void printStack(){
            queue<int> q3=q1;
            while(!q3.empty()){
                cout<<q3.front()<<" ";
                q3.pop();
            }
            cout<<endl;
        }
};

int main(){
    int n;cin>>n;
    Stack_usking_q s(n);
    string a;
    while(cin>>a && a!="-1"){
        if(a=="push"){
            int x;cin>>x;
            s.push(x);
        }
        else if(a=="pop") s.pop();
    }

    return 0;
}