import math 

def build_sparse_table(arr,n):
    log = math.floor(math.log2(n))+1
    st = [[0]*log for i in range(n)]
    for i in range(n):
        st[i][0] = arr[i]
    j = 1
    while j<log:
        i=0
        while i+(1<<j)-1<n:
            st[i][j] = min(st[i][j-1],st[i +(1<<(j-1))][j-1])
            i+=1
        j+=1
    return st,log

def show_ranges_and_tableStat(st,n,log):
    print("Ranges to be stored in Sparse Table:")
    for i in range(n):
        for j in range(log):
            if i + (1<<j)-1 <n:
                print(f"({i},{i+(1<<j)-1})",end =" ")
        print()
    print("\nStatus of Sparse Table:")
    for i in range(n):
        for j in range(log):
            if i + (1<<j)-1 <n:
                print(f"{st[i][j]}",end = " ")
        print()
        
def query(st,l,r):
    j = math.floor(math.log2(r-l+1))
    l_ran = f"[{l},{l+(1<<j)-1}]"
    r_ran = f"[{r-(1<<j)+1},{r}]"
    min_val = min(st[l][j],st[r-(1<<j)+1][j])
    return f"Min = {min_val} min({l_ran},({r_ran})"


n= int(input())
arr = list(map(int,input().split()))
sparse_table,log = build_sparse_table(arr,n)
show_ranges_and_tableStat(sparse_table,n,log)
print()
for i in range(int(input())):
    l,r = map(int,input().split())
    result = query(sparse_table,l,r)
    print(f"Query-{i+1}: {result}")