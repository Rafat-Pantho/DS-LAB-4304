a= [int(i) for i in input().split() if int(i)!=-1]
targ = int(input())
seen = {}
b= []

for i in a:
    if (targ - i) in seen and seen[targ-i]>0:
        b.append((targ-i, i))
        seen[targ-i]-=1
    else: seen[i] = seen[i] + 1 if i in seen else 1
    
print(', '.join(str(i) for i in b) if b else"No pair found")