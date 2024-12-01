s= [str(i) for i in input().split() if i!="-1"]
s.sort(key= len, reverse=True)
s1 = input()
for i in s: s1=s1.replace(i, "")
print("TRUE" if s1=="" else "FALSE")