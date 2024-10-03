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

        Node * Head(){
            return head;
        }

        Node * Tail(){
            return tail;
        }

        void display(){
            if(!head){
                cout<<"Empty"<<endl;
                return;
            }
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

void Intersection(SinglyLinkedList &l1, SinglyLinkedList &l2, SinglyLinkedList &l3){
    Node *temp1=l1.Head();
    Node *temp2=l2.Head();

    while(temp1 && temp2){
        if(temp1->data == temp2->data){
            l3.insert_back(temp1->data);
            while(temp1->data==temp1->next->data)temp1=temp1->next;
            while(temp2->data==temp2->next->data)temp2=temp2->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->data<temp2->data)temp1=temp1->next;
        else temp2=temp2->next;
    }
}

int main(){
    SinglyLinkedList l1,l2,l3;
    int x;
    while(cin>>x && x!=-1)l1.insert_back(x);
    while(cin>>x && x!=-1)l2.insert_back(x);
    Intersection(l1,l2,l3);
    l3.display();
    return 0;
}