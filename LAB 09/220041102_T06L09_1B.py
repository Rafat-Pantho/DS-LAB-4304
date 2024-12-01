def lcp(num1,num2):
    lcp_len =0
    for i in range(min(len(num1),len(num2))):
        if num1[i]== num2[i]:lcp_len+=1
        else:break
    return lcp_len
def find_lcp(a,b):
    max_lcp =0
    for i in a:
        for j in b:max_lcp = max(max_lcp,lcp(i,j))
    return max_lcp
m,n= map(int,input().split())
a = list(map(str,input().split()))
b = list(map(str,input().split()))

print(find_lcp(a,b))