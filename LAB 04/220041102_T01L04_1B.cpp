#include <iostream>

using namespace std;

//creating node for singly Linked list

class Node{
    public:
        int data;
        Node *next;

        Node(int d): data(d),next(nullptr){}
};

class SinglyLinkedList{
    private:
        Node *head;
        Node *tail;

    public:
        SinglyLinkedList():head(nullptr),tail(nullptr){}
        SinglyLinkedList(int a){
            Node *temp = new Node(a);
            head = temp;
            tail = temp;
        }
        ~SinglyLinkedList(){
            while(head){
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
        }

        void insert_front(int key){
            Node *temp = new Node(key);
            temp->next = head;
            head = temp;
            if(tail == nullptr)tail=head;
        }

        void insert_back(int key){
            Node *temp = new Node(key);
            if(tail){
                tail->next = temp;
                tail = temp;
            }
            else head = tail = temp;
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
            temp->next = n;
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
                head = head->next;
                delete temp;
                if(!head)tail = nullptr;
            }
        }

        void remove_element(int key){
            Node *temp = head;
            Node *prev = nullptr;
            while(temp && temp->data!=key){
                prev = temp;
                temp = temp->next;
            }
            if(temp){
                if(prev)prev->next=temp->next;
                else head = temp->next;
                if(temp == tail)tail = prev;
                delete temp;
            }
            else cout<<"Value not Found"<<endl;
        }

        void remove_end(){
            if(!head)cout<<"Underflow"<<endl;
            else if(head == tail){
                delete head;
                head = tail = nullptr;
            }
            else{
                Node *temp = head;
                while (temp->next!=tail)temp=temp->next;
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }

        void display(){
            if(!head){
                cout<<"Head=Null, Tail=Null, Enmpy"<<endl;
                return;
            }
            cout<<"Head="<<head->data<<", Tail="<<tail->data<<", ";
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main(){
    SinglyLinkedList l;
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