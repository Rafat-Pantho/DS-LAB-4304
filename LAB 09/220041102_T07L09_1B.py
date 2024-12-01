def sef_to_cap(word):
    a=""
    b = []
    for i in word:
        if i.isupper() and a:
            b.append(a)
            a=i
        else:a+=i
    if a:b.append(a)
    return b

a= [i for i in input().split() if i!="-1"]
b = input().strip()
b=sef_to_cap(b)
for i in a:
    flag = True 
    h = sef_to_cap(i)
    if len(h)!=len(b):flag=False
    else:
        for j in range(len(h)):
            if b[j] not in h[j]:
                flag=False
                break
    print("T" if flag else "F", end=" ")
print()