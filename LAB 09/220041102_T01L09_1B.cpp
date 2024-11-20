#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define br cout<<endl;

struct TrieNode {
    TrieNode* children[26];
    bool is_word;

    TrieNode(){
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        is_word = false;
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
            TrieNode* node = root;
            for(char c: word){
                int index = c-'a';
                if(!node->children[index]) node->children[index] = new TrieNode();
                node = node->children[index];
            }
            node->is_word = true;
        }

        char search(const string& word){
            TrieNode* node = root;
            for(char c: word){
                if(!node->children[c-'a'])return 'F';
                node = node->children[c-'a'];
            }
            return node->is_word ? 'T' : 'F';
        }

        void display(){
            queue <pair<TrieNode*,string>> q;
            vector<string> v;
            q.push({root,""});
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                TrieNode * t = node.first;
                string s = node.second;
                if(t->is_word)v.push_back(s);
                for(int i=0;i<26;i++){
                    if(t->children[i]){
                        string s1 = s + char(i+ 'a');
                        q.push({t->children[i],s1});
                    }
                }
            }
            sort(v.begin(),v.end());
            for(const string & word: v)cout<<word<<" ";
        }
};

int main(){
    Trie t;
    string s1,s2="",s3;
    getline(cin,s1);
    for(char c:s1){
        if(c==' '){
            t.insert(s2);
            s2="";
        }
        else s2+=c;
    }
    if(s2!="")t.insert(s2);
    s2="";
    t.display();br;
    getline(cin,s3);
    for(char c:s3){
        if(c==' '){
            cout<<t.search(s2)<<" ";
            s2="";
        }
        else s2+=c;
    }
    if(s2!="")cout<<t.search(s2);br;

    return 0;
}