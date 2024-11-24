import sys  
input = sys.stdin.read 
data = input().splitlines()

dictionary = {}
message=[]
flag = True
for i in data:
    if i == "":
        flag = False
        continue
    if flag:
        english,foreign = i.split()
        dictionary[foreign] = english
    else: message.append(i)
    
translation = []
for i in message:translation.append(dictionary.get(i,"eh"))

print("\n".join(translation))