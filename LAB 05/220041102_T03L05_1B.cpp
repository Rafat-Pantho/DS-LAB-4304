#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Node{
    public:
        int data,hight;
        Node *left,*right,*parent;

        Node(int d):data(d),hight(0),left(nullptr),right(nullptr),parent(nullptr){}
        ~Node(){}
};

class BST{
    private:
        Node *root;

    public:
        BST():root(nullptr){}
        ~BST(){}

        void Insert(int d){
            Node* newNode = new Node (d);
            if(!root){
                root = newNode;
                return;
            }

            Node* temp = root;

            while(1){
                if(d < temp->data){
                    if(!temp->left){
                        temp->left = newNode;
                        newNode->parent = temp;
                        break;
                    }
                    else temp = temp->left;
                }
                else{
                    if(!temp->right){
                        temp->right = newNode;
                        newNode->parent = temp;
                        break;
                    }
                    else temp = temp->right;
                }
            }
            update_hight(newNode);
        }

        void update_hight(Node * node){
            while(node){
                node->hight = 1+ max(Hight_returner(node->left),Hight_returner(node->right));
                node=node->parent;
            }
        }

        void Print_tree(){
            inorder(root);
            cout<<endl;
        }

        Node * Search(int a){
            Node *temp = root;
            while(temp && temp->data!= a){
                if(a < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            return temp;
        }

        int Hight_returner(Node * node){
            return node? node->hight:-1;
        }

        int Hight(int val){
            Node * temp = Search(val);
            return Hight_returner(temp);
        }

        void Before_after(int a){
            vector<int> arr;
            collectValues(root,arr);
            for(unsigned int i= 0;i<arr.size();i++)if(arr[i]==a){
                string before = (i>0)? to_string(arr[i-1]):"null";
                string after = (i<arr.size()-1)? to_string(arr[i+1]):"null";
                cout<<before<<" "<<after<<endl;
                return;
            }
        }

        void collectValues(Node * temp, vector<int> & arr){
            if(temp){
                collectValues(temp->left,arr);
                arr.push_back(temp->data);
                collectValues(temp->right,arr);
            }
        }

        void inorder(Node *temp){
            if(temp){
                inorder(temp->left);
                cout<<temp->data<<"("<<(temp->parent? to_string(temp->parent->data):"null")<<") ";
                inorder(temp->right);
            }
        }

        void preorder(Node *node){
            if(!node)return;
            cout<<node->data<<"("<<(node->parent? to_string(node->parent->data):"null")<<") ";
            preorder(node->left);
            preorder(node->right);
        }

        void postorder(Node *node){
            if(!node)return;
            postorder(node->left);
            postorder(node->right);
            cout<<node->data<<"("<<(node->parent? to_string(node->parent->data):"null")<<") ";
        }

        void level_order(){
            if(!root)return;
            queue<Node*>q;
            q.push(root);
            int level= 1;
            while(!q.empty()){
                int level_size = q.size();
                cout<<"Level "<<level++<<": ";
                while(level_size--){
                    Node * container = q.front();
                    q.pop();
                    cout<<container->data<<"("<<(container->parent? to_string(container->parent->data):"null")<<") ";
                    if(container->left)q.push(container->left);
                    if(container->right)q.push(container->right);
                }
                cout<<endl;
            }
        }

        Node * getRoot(){
            return root;
        }

        int LCA(Node * temp, int u, int v){
            if(!temp)return -1;
            if(u<temp->data && v<temp->data) return LCA(temp->left,u,v);
            if(u>temp->data && v>temp->data) return LCA(temp->right,u,v);
            return temp->data;
        }
};

int main(){
    int N,x;cin>>N;
    BST T;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        T.Insert(a);
    }

    cin>>x;
    while(x--){
        int u,v;cin>>u>>v;
        cout<<T.LCA(T.getRoot(),u,v)<<endl;
    }

    return 0;
}