#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define br cout<<endl;

struct node{
    Node children[2];
    Node(){
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie{
    private:
        Node * root;
    
    public:
        Trie(): root(new Node()){}
        ~Trie(){
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node * node = q.front();
                q.pop();
                for(int i=0;i<2;i++)if(node->children[i])q.push(node->children[i]);
                delete node;
            }
        }

        void insert(int num, int maxBits){
            Node * node = root;
            
        }
}