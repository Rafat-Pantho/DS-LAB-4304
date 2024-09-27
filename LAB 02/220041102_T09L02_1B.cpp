#include <iostream>
#include <stack>

using namespace std;

#define br cout<<endl;

class q_on_stack{
    private:
        stack<int> s1, s2;
        int size,max_size;

    public:
        q_on_stack(int s){
            size =0;
            max_size = s;
        }

        void enqueue(int x){
            if (size== max_size){
                cout << "Size:" << size << " Elements: Overflow!";br;
                return;
            }
            s1.push(x);
            size++;

            cout<<"Size:"<<size<<" Elements: ";
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            while(!s2.empty()){
                cout<<s2.top()<<" ";
                s1.push(s2.top());
                s2.pop();
            }

            br;
        }

        void dequeue(){
            if (size==0){
                cout << "Size:0 Elements: Underflow!";br;
                return;
            }

            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
            size--;
            if(size==0){
                cout<<"Size:0 Elements: NULL";br;
                return;
            }
            cout<<"Size:"<<size<<" Elements: ";
            while(!s2.empty()){
                cout<<s2.top()<<" ";
                s1.push(s2.top());
                s2.pop();
            }
            br;
        }
        ~q_on_stack(){}
};

int main(){
    int N, q;
    cin>>N>>q;
    q_on_stack s(N);

    while(q--){
        int choice;cin>>choice;

        switch(choice){
            case 1:
                int x;cin>>x;
                s.enqueue(x);
                break;

            case 2:
                s.dequeue();
                break;
        }
    }

    return 0;
}
