#include <iostream>
#include <string>
#include <vector>

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
                cout<<temp->data<<" ";
                inorder(temp->right);
            }
        }
};


int main(){
    int N,x;cin>>N;
    BST T;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        T.Insert(a);
    }

    T.Print_tree();

    while(cin>>x&&x!=-1){   //*breaks when -1 is given;
        switch(x){
            case 3:{
                int key;cin>>key;
                Node * temp = T.Search(key);
                if(temp) cout<<"Present\nParent("<<(temp->parent?to_string(temp->parent->data):"null")<<"), Left("<<(temp->left?to_string(temp->left->data):"null")<<"), Right("<<(temp->right?to_string(temp->right->data):"null")<<")"<<endl;
                else cout<<"Not Found\n";
                break;
            }
            case 4:
                int key1;cin>>key1;
                cout<<T.Hight(key1)<<endl;
                break;
            case 5:
                int key2;cin>>key2;
                T.Before_after(key2);
                break;
        }
    }

    return 0;
}