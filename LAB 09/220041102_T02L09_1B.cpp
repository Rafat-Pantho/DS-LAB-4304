#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

#define br cout<<endl;

struct TrieNode {
    TrieNode* children[26];
    int pre_cnt = 0;
    bool is_word;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        is_word = false;
        pre_cnt =0;
    }
};

class Trie{
    private:
        TrieNode* root;

    public:
        Trie(): root(new TrieNode()){}
        ~Trie() {
            queue<TrieNode*> q;
            q.push(root);
            while(!q.empty()){
                TrieNode* node = q.front();
                q.pop();
                for(int i=0;i<26;i++)if(node->children[i])q.push(node->children[i]);
                delete node;
            }
        }
        void insert(const string& word){
            if(search(word)) return;
            TrieNode * node = root;
            for(char c: word){
                if(!node->children[tolower(c)-'a']) node->children[tolower(c)-'a'] = new TrieNode();
                node = node->children[tolower(c)-'a'];
                node->pre_cnt++;
            }
            node->is_word = true;
        }

        bool search(const string& word){
            TrieNode * node = root;
            for(char c: word){
                if(!node->children[tolower(c)-'a']) return false;
                node = node->children[tolower(c)-'a'];
            }
            return node->is_word;
        }

        int count(const string& word){
            TrieNode * node = root;
            for(char c: word){
                if(!node->children[tolower(c)-'a']) return 0;
                node = node->children[tolower(c)-'a'];
            }
            return node->pre_cnt;
        }
};

int main(){
    Trie t;
    int n,q;cin>>n>>q;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        t.insert(s);
    }

    for(int i=0;i<q;i++){
        string s;cin>>s;
        cout<<t.count(s)<<endl;
    }

    return 0;
}