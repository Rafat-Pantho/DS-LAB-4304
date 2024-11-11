#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

#define br cout<<endl;

struct Node{
    char data;
    Node *l,*r;

    Node(char d):data(d),l(nullptr),r(nullptr){};
    ~Node(){}
};

class AVLTree{
    public:
        Node * root;

        Node * insert(Node *n,char d){
            if(!n) return new Node(d);
            if(d < n->data) n->l = insert(n->l,d);
            else if(d > n->data) n->r = insert(n->r,d);
            else return n;
            return n;
        }
    
    public:
        AVLTree():root(nullptr){}; 
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

        void insert(char d){
            root = insert(root,d);
        }

        void print_tree_inorder(Node *n){
            if(n){
                print_tree_inorder(n->l);
                cout<<n->data<<" ";
                print_tree_inorder(n->r);
            }
            else cout<<"- ";
        }

        void print_tree_postorder(Node *n){
            if(n){
                print_tree_postorder(n->l);
                print_tree_postorder(n->r);
                cout<<n->data<<" ";
            }
            else cout<<"- ";
        }

        void build_avl_from_preorder(vector<char> &preorder,int &i, Node *&temp){
            if(preorder[i]=='-'||i>=preorder.size()){
                i++;
                return;
            }

            temp = new Node(preorder[i++]);
            build_avl_from_preorder(preorder,i,temp->l);
            build_avl_from_preorder(preorder,i,temp->r);
        }
};

int main(){
    AVLTree tree;
    vector<char> preorder;
    string x;
    getline(cin,x);
    for(int i=0;x[i];i++)if(x[i]!=' ')preorder.push_back(x[i]);
    int i =0;
    tree.build_avl_from_preorder(preorder,i,tree.root);
    cout<<"Inorder: ";
    tree.print_tree_inorder(tree.root);br;
    cout<<"Postorder: ";
    tree.print_tree_postorder(tree.root);br;
    return 0;
}