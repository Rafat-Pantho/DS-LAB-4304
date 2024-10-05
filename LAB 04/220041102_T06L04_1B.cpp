#include <iostream>

using namespace std;

//creating node for singly Linked list

class Node{
    public:
        int data;
        Node *heap_below;

        Node(int d): data(d),heap_below(nullptr){}
};

class Stack_withLL{
    private:
        Node *heap;
        int size,capasity;

    public:
        Stack_withLL(int n):heap(nullptr),size(0),capasity(n){}
        ~Stack_withLL(){
            while(heap){
                Node *temp = heap;
                heap = heap->heap_below;
                delete temp;
            }
        }

        void push(int d){
            if(size==capasity){
                cout<<"Overflow"<<endl;
                return;
            }
            Node *temp = new Node(d);
            temp->heap_below = heap;
            heap = temp;
            size++;
        }
        void pop(){
            if(!size){
                cout<<"Underflow"<<endl;
                return;
            }
            Node *temp = heap;
            heap = heap->heap_below;
            delete temp;
            size--;
        }

        int top(){
            return heap->data;
        }

        bool isEmpty(){
            return size==0;
        }

        bool isFull(){
            return size==capasity;
        }

        int getsize(){
            return size;
        }

        Node * Heap(){
            return heap;
        }
};

void display(Stack_withLL s){
    Node *temp = s.Heap();
    Stack_withLL s2(s.getsize());
    while(temp){
        s2.push(temp->data);
        temp = temp->heap_below;
    }

    while(!s2.isEmpty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<endl;
}

int main(){
    int N;
    cin>>N;
    Stack_withLL s(N);
    while(1){
        int x;cin>>x;
        if(x==-1)break;
        switch (x){
            case 1:
                int y;cin>>y;
                s.push(y);
                display(s);
                break;

            case 2:
                s.pop();
                display(s);
                break;

            case 3:
                (s.isEmpty())?cout<<"True"<<endl:cout<<"False"<<endl;
                break;
            
            case 4:
                (s.isFull()) ? cout << "True" << endl : cout << "False" << endl;
                break;

            case 5:
                cout<<s.getsize()<<endl;
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
