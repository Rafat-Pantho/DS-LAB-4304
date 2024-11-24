a= input().split()
tar = input()

store = set() 
for i in a:
    if i is tar:
        store.add(i)
        continue
    flag = True
    for j in i:
        if j not in tar:
            flag = False
            break
    for j in tar:
        if j not in i:
            flag = False
            break
    if flag: store.add(i)
print(' '.join(str(i) for i in store))