//* still bugs needs to be fixed!!!!!!!
#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <ctime>

using namespace std;

#define br cout<<endl;

template <typename t>
struct AVLNode{
    t data;
    AVLNode *l,*r;
    int hight;

    AVLNode(t val):data(val),l(nullptr),r(nullptr), hight(1){}
    ~AVLNode() {}
};

template <typename t>
class AVLTree {
    private:
        AVLNode<t>* root;

        int getHight(AVLNode<t> * temp)const{
            return temp? temp->hight:0;
        }
        int getBalFact(AVLNode<t>* temp) const{
            return temp? getHight(temp->l) - getHight(temp->r):0;
        }

        void updateHight(AVLNode<t> * temp){
            temp->hight = max(getHight(temp->l), getHight(temp->r)) +1;
        }

        AVLNode<t> * rightRotate(AVLNode<t> *y){
            AVLNode<t> *x=y->l, *t2 = x->r;
            x->r=y;
            y->l=t2;
            updateHight(y);
            updateHight(x);
            return x;
        }

        AVLNode <t> * leftRotate(AVLNode<t> *x){
            AVLNode<t> *y=x->r, *t2= y->l;
            y->l=x;
            x->r=t2;
            updateHight(x);
            updateHight(y);
            return y;
        }

        AVLNode<t> * balance(AVLNode<t> *temp){
            int balFac = getBalFact(temp);
            if(balFac > 1){
                if(getBalFact(temp->l)<0) temp->l=leftRotate(temp->l);
                return rightRotate(temp);
            }
            if(balFac < -1){
                if(getBalFact(temp->r)>0) temp->r = rightRotate(temp->r);
                return leftRotate(temp);
            }
            return temp;
        }

    public:
        AVLTree() : root(nullptr){}
        ~AVLTree() {
            clear();
        }

        void insert(t val){
            AVLNode<t> * temp = new AVLNode<t> (val);
            if(!root){
                root = temp;
                return;
            }

            stack<AVLNode<t>*>path;
            AVLNode<t> *curr = root, *par = nullptr;
            while(curr){
                par = curr;
                path.push(curr);
                if(val < curr->data) curr = curr->l;
                else if(val > curr->data) curr=curr->r;
                else{
                    cerr<<"Duplicate Value in AVL tree"<<endl;
                    delete temp;
                    return;
                }
            }

            if(val<par->data)par->l=temp;
            else par->r=temp;

            while(!path.empty()){
                curr = path.top(); path.pop();
                updateHight(curr);
                curr = balance(curr);
                if(!path.empty()){
                    par = path.top();
                    if(par->l == curr|| (par->l && par->l->data==curr->data) )par->l=curr;
                    else par->r=curr;
                }
                else root = curr;
            }
        }

        void remove(t val){
            AVLNode<t> *curr= root, *par= nullptr;
            stack<AVLNode<t>*>path;
            while(curr && curr->data!=val){
                par= curr;
                path.push(curr);
                if(val < curr->data) curr = curr->l;
                else curr=curr->r;
            }
            if(!curr){
                cerr<<"Value not found in AVL tree"<<endl;
                return;
            }
            if(curr->l && curr->r){
                AVLNode<t>* sucPar = curr, * suc = curr->r;
                path.push(curr);
                while(suc->l){
                    sucPar = suc;
                    path.push(suc);
                    suc = suc->l;
                }
                curr->data = suc->data;
                curr = suc;
                par = sucPar;
            }
            AVLNode<t>*child= curr->l?curr->l:curr->r;
            if(!par) root = child;
            else if(par->l==curr)par->l=child;
            else par->r = child;
            delete curr;
            while(!path.empty()){
                curr= path.top();path.pop();
                updateHight(curr);
                curr = balance(curr);
                if(!path.empty()){
                    par = path.top();
                    if(par->l == curr || (par->l && par->l->data==curr->data) )par->l = curr;
                    else par->r = curr;
                }
                else root = curr;
            }
        }

        bool search(t val) const{
            AVLNode<t>* curr = root;
            while(curr){
                if(val == curr->data) return true;
                else if(val < curr->data ) curr= curr->l;
                else curr= curr->r;
            }
            return false;
        }

        void inorder() const{
            stack<AVLNode<t>*> stacking;
            AVLNode<t>* curr = root;
            while(curr || !stacking.empty()){
                while(curr){
                    stacking.push(curr);
                    curr = curr->l;
                }
                curr = stacking.top();
                stacking.pop();
                cout << curr->data << " ";
                curr = curr->r;
            }
            br;
        }

        void clear(){
            stack<AVLNode<t>*> nodeStack;
            if(root)nodeStack.push(root);
            while(!nodeStack.empty()){
                AVLNode<t>* curr = nodeStack.top();
                nodeStack.pop();
                if(curr->l)nodeStack.push(curr->l);
                if(curr->r)nodeStack.push(curr->r);
                delete curr;
            }
            root = nullptr;
        }
        bool isEmpty() const{
            return root == nullptr;
        }
};

int main(){
    srand(time(0));
    AVLTree<int> tree;
    for(int i = 0; i < 30; i++) tree.insert(rand()%200+1);
    tree.inorder();
    tree.insert(100);
    tree.insert(50);
    tree.insert(150);
    tree.insert(25);
    tree.insert(75);
    tree.inorder();
    tree.remove(100);
    tree.inorder();
    tree.remove(100);
    cout << "Search 100: " << tree.search(100) <<endl;
    cout << "Search 150: " << tree.search(150) <<endl;
    cout << "Is Empty: " << tree.isEmpty() << endl;
    return 0;
}