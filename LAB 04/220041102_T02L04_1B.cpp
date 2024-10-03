#include <iostream>

using namespace std;

//creating node for singly Linked list

class Node{
    public:
        int data;
        Node *next,*prev;

        Node(int d): data(d),next(nullptr),prev(nullptr){}
};

class DoublyLinkedList{
    private:
        Node *head;
        Node *tail;

    public:
        DoublyLinkedList():head(nullptr),tail(nullptr){}
        DoublyLinkedList(int a){
            Node *temp = new Node(a);
            head = temp;
            tail = temp;
        }
        ~DoublyLinkedList(){
            while(head){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
        }

        void insert_front(int key){
            Node *temo = new Node(key);
            if(!head)head= tail = temo;
            else{
                temo->next = head;
                head->prev = temo;
                head = temo;
            }
        }

        void insert_back(int key){
            Node *temo = new Node(key);
            if(!tail)head = tail = temo;
            else{
                tail->next= temo;
                temo->prev= tail;
                tail = temo;
            }
        }

        void insert_after_node(int key, int v){
            Node *temp = head;
            while(temp && temp->data != v)temp=temp->next;
            if(!temp){
                cout<<"Value not Found"<<endl;
                return;
            }
            Node *n = new Node(key);
            n->next = temp->next;
            if(temp->next)temp->next->prev=n;
            n->prev = temp;
            temp->next= n;
            if(temp == tail)tail = n;
        }

        void update_node(int key,int v){
            Node *temp = head;
            while(temp && temp->data != v)temp=temp->next;
            if(!temp){
                cout<<"Value not Found"<<endl;
                return;
            }
            temp->data = key;
        }

        void remove_head(){
            if(!head)cout<<"Underflow"<<endl;
            else{
                Node *temp = head;
                if(head==tail)head= tail = nullptr;
                else{
                    head = head->next;
                    head->prev = nullptr;
                }
                delete temp;
            }
        }

        void remove_element(int key){
            Node *temp = head;
            while(temp && temp->data !=key)temp= temp->next;
            if(!temp){
                cout<<"Value not Found"<<endl;
                return;
            }
            if(temp==head)remove_head();
            else if(temp==tail)remove_end();
            else{
                temp->prev->next= temp->next;
                temp->next->prev= temp->prev;
                delete temp;
            }
        }

        void remove_end(){
            if(!tail){
                cout<<"Underflow"<<endl;
                return;
            }
            Node *temp = tail;
            if(head==tail)head= tail = nullptr;
            else{
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
        }

        void display(){
            if(!head){
                cout<<"Head=Null, Tail=Null, Enmpy"<<endl;
                return;
            }
            cout<<"Head="<<head->data<<", Tail="<<tail->data<<endl;
            cout<<"From Head to Tail: ";
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
            cout<<"From Tail to Head: ";
            Node* temp1 = tail;
            while(temp1){
                cout<<temp1->data<<" ";
                temp1 = temp1->prev;
            }
            cout<<endl;
        }
};


int main(){
    DoublyLinkedList l;
    int x;
    while(cin>>x && x!=8){
        switch(x){
            case 1:
                int key;cin>>key;
                l.insert_front(key);
                l.display();
                break;
            
            case 2:
                int key1;cin>>key1;
                l.insert_back(key1);
                l.display();
                break;
            
            case 3:
                int key3,v;cin>>key3>>v;
                l.insert_after_node(key3,v);
                l.display();
                break;
            
            case 4:
                int key4, v1;cin>>key4>>v1;
                l.update_node(key4,v1);
                l.display();
                break;
            
            case 5:
                l.remove_head();
                l.display();
                break;
            
            case 6:
                int key6;cin>>key6;
                l.remove_element(key6);
                l.display();
                break;
            
            case 7:
                l.remove_end();
                l.display();
                break;
            
            case 8:
                l.display();
                break;
        }
    }

    return 0;
}