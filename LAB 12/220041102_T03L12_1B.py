from collections import deque
def find_path(map_citis_path, src,dst,k):
    storer =deque([[src]])
    while storer:
        path = storer.popleft()
        last_city = path[-1]
        if last_city == dst:
            print(' '.join(path))
            return
        for ssh in map_citis_path[last_city]:
            if ssh not in path:
                if (len(path)-1)%k == 0:
                    np = path + [ssh]
                    storer.append(np)
    print("NO")            

V,E, Q = map(int,input().split())
cities = input().split()
map_citis_path ={cty:[] for cty in cities}
for i in range(E):
    u,v=input().split()
    map_citis_path[u].append(v)
    map_citis_path[v].append(u)
for i in range(Q):
    src,dst,k=input().split()
    find_path(map_citis_path,src,dst,int(k))