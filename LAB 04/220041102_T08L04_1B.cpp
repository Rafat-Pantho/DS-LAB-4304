#include <iostream>
#include <string>

using namespace std;

template <class trex>
class Node{
    public:
        trex data;
        Node<trex> * next;

        Node(trex n):data(n),next(nullptr){}
        ~Node(){}
};

template <class trex>
class Silgly_ll{
    private:
        Node<trex> *head;
    
    public:
        Silgly_ll():head(nullptr){}
        ~Silgly_ll(){
            while(head){
                Node<trex> *temp = head;
                head = head->next;
                delete temp;
            }
        }

        void push_back(trex key){
            Node<trex> *temp = new Node<trex>(key);
            if(!head)head = temp;
            else{
                Node<trex> *temp1 = head;
                while(temp1->next)temp1 = temp1->next;
                temp1->next = temp;
            }
        }

        void rearrange_ll(){
            if(!head||!head->next)return;
            Node<trex> *temp = head,*temp1=head->next,*perm=head->next;

            while(temp->next&&temp1->next){
                temp->next=temp1->next;
                temp=temp->next;
                temp1->next=temp->next;
                temp1=temp1->next;
            }
            temp->next= perm;
        }

        void display(){
            Node<trex> *temp = head;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
};

int main(){
    Silgly_ll<int> l1;
    string s;
    while(cin>>s){
        if(s=="NULL")break;
        l1.push_back(stoi(s));
    }
    l1.rearrange_ll();
    l1.display();

    return 0;
}

