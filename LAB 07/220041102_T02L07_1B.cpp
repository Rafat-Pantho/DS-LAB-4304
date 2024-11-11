#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

#define br cout<<endl;

struct Node {
    int data,hight;
    Node *l, *r, *p;

    Node(int d):data(d),hight(0),l(nullptr),r(nullptr),p(nullptr){}
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

        int balFact(Node *n){
            return getHight(n->l)-getHight(n->r);
        }

        void updateHight(Node *n){
            while(n){
                n->hight = max(getHight(n->l),getHight(n->r))+1;
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

        bool balance(Node *temp){
            bool was_balanced = true;
            while(temp){
                updateHight(temp);
                int bf= balFact(temp);
                if(bf>1){
                    was_balanced = false;
                    if(balFact(temp->l)<0){
                        cout<<"Imbalance at node: "<<temp->data<<"\nLR case"<<endl;
                        leftRotate(temp->l);
                    }
                    else cout<<"Imbalance at node: "<<temp->data<<"\nLL case"<<endl;
                    rightRotate(temp);
                }
                else if(bf < -1){
                    was_balanced = false;
                    if(balFact(temp->r)>0){
                        cout<<"Imbalance at node: "<<temp->data<<"\nRL case"<<endl;
                        rightRotate(temp->r);
                    }
                    else cout<<"Imbalance at node: "<<temp->data<<"\nRR case"<<endl;
                    leftRotate(temp);
                }
                temp = temp->p;
            }
            return was_balanced;
        }

        void insert(Node * &root,int d){
            if(!root){
                root = new Node(d);
                print_tree();
                cout<<"Balanced"<<endl;
                cout<<"Root="<<root->data<<endl;
                return;
            }
            Node *temp = root, *container = new Node(d), *par=nullptr;
            
            while(temp){
                par = temp;
                if(temp->data>d)temp = temp->l;
                else if(temp->data<d) temp = temp->r;
                else{
                    cout<<"Data already exist\n";
                    return;
                }
            }

            container->p = par;
            if(d<par->data)par->l = container;
            else par->r = container;

            updateHight(container);
            print_tree();

            bool was_balanced = balance(par);
            if(was_balanced){
                cout<<"Balanced"<<endl;
                cout<<"Root="<<root->data<<endl;
            }
            else{
                cout<<"status:";
                print_tree();
                cout<<"Root="<<root->data<<endl;
            }
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

            if (par) {
                updateHight(par);
                bool was_balanced = balance(par);
                if (was_balanced) {
                    cout << "Balanced" << endl;
                    cout << "Root=" << root->data << endl;
                } else {
                    cout << "Status:";
                    print_tree();
                }
            }
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
};

int main(){
    AVLTree a;
    string val;
    while(cin>>val && val!="-1"){
        if(isalpha(val[0])){
            int d;cin>>d;
            a.delete_key(d);
        }
        else a.insert(stoi(val));
    }
    cout<<"Status:";
    a.print_tree();
    return 0;
}