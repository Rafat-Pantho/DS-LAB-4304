#include<iostream>
using namespace std;

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
                cout<<"Overflow !!!"<<endl;
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

        void printStack() {
        if (last >= 0) {
            cout << "Stack elements : ";
            for (int i = 0; i <= last; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        } else {
            cout << "Stack elements : " << endl;
        }
    }

        ~stack(){
            delete []arr;
        }
};


int main(){
    int N;cin>>N;
    cin.ignore();

    stack s(N);

    while(true){
        char c; cin>>c;
        getchar();

        if (c=='/')break;

        switch(c){
            case '+':
                int n;
                cin >> n;
                getchar();
                s.push(n);
                cout << "Size : " << s.size() << endl;
                s.printStack();
                cout << "Top Element : " << (s.isEmpty() ? 0 : s.top()) << endl;
                cout << "isFull : " << (s.isFull() ? "True" : "False") << endl;
                cout << "isEmpty : " << (s.isEmpty() ? "True" : "False") << endl;
                break;
            
            case '-':
                int popped;
                s.pop();
                cout << "Size : " << s.size() << endl;
                s.printStack();
                cout << "Top Element : " << (s.isEmpty() ? 0 : s.top()) << endl;
                cout << "isFull : " << (s.isFull() ? "True" : "False") << endl;
                cout << "isEmpty : " << (s.isEmpty() ? "True" : "False") << endl;
                break;
        }
    }
}