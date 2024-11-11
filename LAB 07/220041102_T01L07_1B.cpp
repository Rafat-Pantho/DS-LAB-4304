#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define br cout<<endl;

struct Node {
    int data,hight;
    Node *l, *r, *p;
    //*constructor
    Node(int d):data(d),hight(0),l(nullptr),r(nullptr),p(nullptr){}
    ~Node(){
        delete l;
        delete r;
        delete p;
    }
};

class BST{
    private:
        Node *root;

    public:
        BST():root(nullptr){}

        //*destructors----------------------------------------
        ~BST(){
            deletetree(root);
        }

        void deletetree(Node *n){
            if(n){
                deletetree(n->l);
                deletetree(n->r);
                delete n;
            }
        }
        //*end of destructors----------------------------------

        void insert(int d){
            Node *temp = new Node(d);
            if(!root){
                root = temp;
                return;
            }

            Node * temp2 = root;
            while(1){
                if(temp2->data>d){
                    if(!temp2->l){
                        temp2->l = temp;
                        temp->p = temp2;
                        break;
                    }
                    else temp2 = temp2->l;
                }
                else if(temp2->data<d){
                    if(!temp2->r){
                        temp2->r=temp;
                        temp->p = temp2;
                        break;
                    }
                    else temp2 = temp2->r;
                }
            }

            update_hight(temp);
        }

        void update_hight(Node *n){
            while(n){
                n->hight = 1+max(getHight(n->l),getHight(n->r));
                n = n->p;
            }
        }

        int getHight(Node *n){
            return n?n->hight:-1;
        }

        int balFact(Node *n){
            return getHight(n->l)-getHight(n->r);
        }

        void inorder(Node *n){
            if(n){
                inorder(n->l);
                cout<<n->data<<"("<<balFact(n)<<") ";
                inorder(n->r);
            }
        }

        void print_tree(){
            inorder(root);
            br;
        }
};

int main(){
    BST a;
    int val;
    while(cin>>val && val!=-1){
        a.insert(val);
        a.print_tree();
    }
    return 0;
}