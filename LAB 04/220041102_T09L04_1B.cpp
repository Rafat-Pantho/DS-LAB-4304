#include <iostream>

using namespace std;

template <class trex>
class Node{
    public:
        trex data;
        Node<trex> *next;

        Node(trex d):data(d),next(nullptr){}
        ~Node(){}
};

template <class T_rex>
class Queue_withll{
    private:
        Node<T_rex> *head,*tail;
        int size,capacity;

    public:
        Queue_withll(int n):head(nullptr),tail(nullptr),size(0),capacity(n){}
        ~Queue_withll(){
            while(head){
                Node<T_rex> *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void enQueue(T_rex key){
            if(size == capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            Node<T_rex> *temp = new Node<T_rex>(key);
            if(!tail)head = tail = temp;
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
            display();
        }
        void deQueue(){
            if(size==0){
                cout<<"Underflow"<<endl;
                return;
            }
            Node<T_rex> *temp = head;
            head = head->next;
            if(!head)tail=nullptr;
            delete temp;
            size--;
            display();
        }
        bool isEmpty(){
            return size == 0;
        }
        bool isFull(){
            return size == capacity;
        }
        int getSize(){
            return size;
        }

        T_rex front(){
            return head->data;
        }

        void display(){
            Node<T_rex> *temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main(){
    int N,x;cin>>N;
    Queue_withll<int> s(N);

    while(cin>>x&&x!=-1){
        switch(x){
            case 1:
                int key;cin>>key;
                cout<<"EnQueue: ";
                s.enQueue(key);
                break;
            case 2:
                cout<<"DeQueue: ";
                s.deQueue();
                break;
            case 3:
                cout<<"isEmpty: "<<(s.isEmpty()?"True":"False")<<endl;
                break;
            case 4:
                cout<<"isFull: "<<(s.isFull()?"True":"False")<<endl;
                break;
            case 5:
                cout<<"Size: "<<s.getSize()<<endl;
                break;
            case 6:
                cout<<"Front: "<<s.front()<<endl;
                break;
        }
    }

    cout<<"Exit"<<endl;

    return 0;
}