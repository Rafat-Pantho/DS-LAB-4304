def preprocess_freq(arr,n):
    max_l = [0]*n
    max_r = [0]*n
    max_l[0] = arr[0]
    for i in range(1,n):
        max_l[i]=max(max_l[i-1],arr[i])
    return max_l

n,m = map(int,input().split())
a= list(map(int,input().split()))
ml = preprocess_freq(a,n)
keep_count =0
for i in range(m):
    l,r= map(int,input().split())
    l-=1
    r-=1
    if l==r:
        keep_count+=1
        continue
    max_cnt_btn = max(a[l+1:r]) if l+1<=r-1 else 0
    if max_cnt_btn<=a[l]:
        keep_count+=1
print(keep_count)
