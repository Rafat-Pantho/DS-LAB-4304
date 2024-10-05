#include<iostream>

using  namespace std;


template <class T_rex>
class Node{
    public:
        T_rex data;
        Node<T_rex> *next,*prev;
        Node(T_rex d):data(d),next(nullptr),prev(nullptr){}
};

template <class T_rex>
class Deque_withll{
    private:
        Node<T_rex> *head,*tail;
        int size;
    public:
        Deque_withll():head(nullptr),tail(nullptr),size(0){}
        ~Deque_withll(){
            while(head){
                Node<T_rex> *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push_front(T_rex key){
            Node<T_rex> *temp = new Node<T_rex>(key);
            if(!head)head=tail = temp;
            else{
                temp->next=head;
                head->prev = temp;
                head = temp;
            }
            size++;
            display();
        }

        void push_back(T_rex key){
            Node<T_rex> *temp = new Node<T_rex>(key);
            if(!tail)head= tail = temp;
            else{
                temp->prev=tail;
                tail->next=temp;
                tail= temp;
            }
            size++;
            display();
        }

        void pop_front(){
            if(!head){
                cout<<"Underflow"<<endl;
                return;
            }
            Node<T_rex> *temo = head;
            head = head->next;
            if(head)head->prev=nullptr;
            delete temo;
            size--;
            display();
        }

        void pop_back(){
            if(!tail){
                cout<<"Underflow"<<endl;
                return;
            }
            Node<T_rex> *temp = tail;
            tail=tail->prev;
            if(tail)tail->next=nullptr;
            delete temp;
            size--;
            display();
        }

        int getSize(){
            return size;
        }

        void display(){
            Node<T_rex> *temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main(){
    Deque_withll<int> d;
    int x;
    while(cin>>x &&x!=6){
        switch(x){
            case 1:
                int key;cin>>key;
                d.push_front(key);
                break;
            case 2:
                int key1;cin>>key1;
                d.push_back(key1);
                break;
            case 3:
                d.pop_front();
                break;
            case 4:
                d.pop_back();
                break;
            case 5:
                cout<<d.getSize()<<endl;
                break;
        }
    }

    return 0;
}
