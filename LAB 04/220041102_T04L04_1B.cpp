#include <iostream>

using namespace std;

template <class T_rex>
class Node{
    public:
        T_rex data;
        Node <T_rex> *next;

        Node(T_rex d):data(d),next(nullptr){}
};

template <class T_rex>
class Singly_LL{
    private:
        Node<T_rex> *head;
    
    public:
        Singly_LL():head(nullptr){}
        ~Singly_LL(){
            while(head){
                Node<T_rex> *temp=head;
                head=head->next;
                delete temp;
            }
        }
        void push_back(T_rex key){
            Node<T_rex> *temp = new Node<T_rex>(key);
            if(!head)head=temp;
            else{
                Node<T_rex> *temp1= head;
                while(temp1->next)temp1=temp1->next;
                temp1->next=temp;
            }
        }

        void remove_same(){
            Node<T_rex> *temp=head;
            while(temp->next){
                if(temp->data==temp->next->data){
                    Node<T_rex> *temp1=temp->next;
                    temp->next=temp1->next;
                    delete temp1;
                }
                else temp=temp->next;
            }
        }

        void display(){
            Node<T_rex> *temp=head;
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main(){
    Singly_LL<int> l1;
    int x;
    while(cin>>x && x!=-1)l1.push_back(x);
    l1.remove_same();
    l1.display();
    return 0;
}