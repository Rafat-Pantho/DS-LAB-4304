class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False
        self.words = []
        
class Trie:
    def __init__(self):
        self.root=TrieNode()
        
    def insert(self,word):
        node = self.root
        for c in word:
            if c not in node.children:node.children[c]=TrieNode()
            node = node.children[c]
            if len(node.words)<3:node.words.append(word)
        node.isEnd=True
    
    def search_prefix(self,prefix):
        node = self.root
        for c in prefix:
            if c not in node.children: return []
            node = node.children[c]
        return node.words 
    
def suggested_products(products, search_word):
    products.sort()
    a_trie = Trie()
    for product in products:a_trie.insert(product)
    resu = []
    prefix = ""
    for c in search_word:
        prefix += c
        resu.append(a_trie.search_prefix(prefix))
    return resu

a = input().split()
s = input()
result = suggested_products(a, s)
print('\n'.join([' '.join(x) for x in result]))