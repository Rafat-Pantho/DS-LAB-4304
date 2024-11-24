class Trinode:
    def __init__(self) -> None:
        self.children = {}

class Trie:
    def __init__(self) -> None:
        self.root = Trinode()
    
    def insert(self,num):
        temp = self.root
        for i in range(31,-1,-1):
            bit = (num >> i) & 1
            if bit not in temp.children:temp.children[bit]= Trinode()
            temp = temp.children[bit]
            
    def find_max_xor(self,num):
        temp = self.root
        max_xor = 0
        for i in range(31,-1,-1):
            bit = (num >> i) & 1
            opposite_bit = 1-bit
            if opposite_bit in temp.children:
                max_xor = (max_xor << 1) | 1
                temp = temp.children[opposite_bit]
            else:
                max_xor = (max_xor << 1)
                temp = temp.children[bit]
        return max_xor

num = [int(x) for x in input().split()]
t = Trie()
max_xor = 0
t.insert(num[0])
for i in num[1:]:
    max_xor = max(max_xor,t.find_max_xor(i))
    t.insert(i)

print(max_xor)
