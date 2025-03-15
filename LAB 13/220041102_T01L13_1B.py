def preprocess_freq(s):
    n=len(s)
    prefix_freq = [[0]*26 for _ in range(n+1)]
    for i in range(n):
        index_26 = ord(s[i])-97
        for j in range(26):
            prefix_freq[i+1][j] = prefix_freq[i][j]
        prefix_freq[i+1][index_26]+=1
    return prefix_freq
def most_common_char(arr,l,r)->chr:
    l -=1
    max_freq=0
    rez_car = 'z'
    for i in range(26):
        fre = arr[r][i]-arr[l][i]
        if fre>max_freq or (fre==max_freq and chr(i+97)<rez_car):
            max_freq = fre
            rez_car = chr(i+97)
    return rez_car
s= input().strip()
s1 = preprocess_freq(s)

for i in range(int(input())):
    l,r = map(int, input().split())
    print(most_common_char(s1,l,r))