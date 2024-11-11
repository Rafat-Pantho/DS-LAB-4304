#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

#define br cout<<endl;

struct Node {
    int data,hight,sts;//*sts= subtree size
    Node *l, *r, *p;

    Node(int d):data(d),hight(0),l(nullptr),r(nullptr),p(nullptr),sts(1){}
    ~Node(){
        delete l;
        delete r;
        delete p;
    }
};

class AVLTree{
    private:
        Node *root;

        int getHight(Node *n){
            return n?n->hight:0;
        }

        int getSts(Node *n){
            return n? n->sts:0;
        }

        int balFact(Node *n){
            return getHight(n->l)-getHight(n->r);
        }

        void updateHight(Node *n){
            while(n){
                n->hight = max(getHight(n->l),getHight(n->r))+1;
                n->sts = getSts(n->l)+getSts(n->r)+1;
                n=n->p;
            }
        }

        void leftRotate(Node *x){
            Node *y =x->r;
            x->r = y->l;
            if(y->l)y->l->p=x;
            y->p = x->p;
            if(!y->p)root=y;
            else if(x==x->p->l) x->p->l=y;
            else x->p->r=y;
            y->l =x;
            x->p = y;

            updateHight(x);
            updateHight(y);
        }

        void rightRotate(Node *y){
            Node *x = y->l;
            y->l = x->r;
            if(x->r)x->r->p = y;
            x->p = y->p;
            if(!y->p)root=x;
            else if(y==y->p->l)y->p->l=x;
            else y->p->r=x;
            x->r = y;
            y->p = x;

            updateHight(y);
            updateHight(x);
        }

        void balance(Node *temp){
            while(temp){
                updateHight(temp);
                int bf= balFact(temp);
                if(bf>1){
                    if(balFact(temp->l)<0)leftRotate(temp->l);
                    rightRotate(temp);
                }
                else if(bf < -1){
                    if(balFact(temp->r)>0)rightRotate(temp->r);
                    leftRotate(temp);
                }
                temp = temp->p;
            }
        }

        void insert(Node * &root,int d){
            if(!root){
                root = new Node(d);
                return;
            }
            Node *temp = root, *container = new Node(d), *par=nullptr;
            
            while(temp){
                par = temp;
                if(temp->data>d)temp = temp->l;
                else if(temp->data<d) temp = temp->r;
                else{
                    cout<<"Data already exist\n";
                    delete container;
                    return;
                }
            }

            container->p = par;
            if(d<par->data)par->l = container;
            else par->r = container;

            updateHight(container);
            balance(par);
        }

        void inorder(Node *n){
            if(n){
                inorder(n->l);
                cout<<n->data<<"("<<balFact(n)<<") ";
                inorder(n->r);
            }
        }

        Node *find_min(Node *n){
            while(n->l) n = n->l;
            return n;
        }

        void delete_node(Node *n) {
            if (!n) return;

            Node *par = n->p;

            if (!n->l && !n->r) { 
                if (n == root) root = nullptr;
                else if (par->l == n) par->l = nullptr;
                else par->r = nullptr;
                delete n;
            } 
            else if (n->l && n->r) {
                Node *successor = find_min(n->r), *suc_par = successor->p;
                n->data = successor->data;
                
                if(successor->p->l==successor)successor->p->l=successor->r;
                else successor->p->r=successor->r;
                

                delete successor; 
                updateHight(suc_par);
            } 
            else { 
                Node *child = (n->l) ? n->l : n->r;
                child->p = par;
                if (n == root) root = child;
                else if (par->l == n) par->l = child;
                else par->r = child;
                delete n;
            }

            if (par) updateHight(par);
        }


    public:
        AVLTree():root(nullptr){}

        //*destructors----------------------------------------
        ~AVLTree(){
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
            insert(root,d);
        }

        void print_tree(){
            inorder(root);
            br;
        }

        void delete_key(int d){
            Node *temp = root;
            while(temp && temp->data!=d)temp = temp->data>d?temp->l:temp->r;
            if(temp){
                delete_node(temp);
                print_tree();
                cout<<"Root="<<root->data<<endl;
            }
            else cout<<"Data not found"<<endl;
        }

        int lowerCount(int a){
            int cnt = 0;
            Node * temp = root;
            while(temp){
                if (temp->data < a){
                    cnt+=getSts(temp->l)+1;
                    temp = temp->r;
                }
                else temp = temp->l;
            }
            return cnt;
        }
};

int main(){
    AVLTree a;
    int val;
    while(cin>>val && val!=-1)a.insert(val);
    while(cin>>val && val!=-1)cout<<a.lowerCount(val)<<endl;

    return 0;
}