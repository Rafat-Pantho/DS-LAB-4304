from collections import defaultdict 
from math import gcd 

def max_pnt_on_line(points):
    def find_slop(p1,p2):
        dx= p2[0]-p1[0]
        dy = p2[1]-p1[1]
        if dx == 0: return float('inf'),0
        elif dy==0: return 0, float('inf')
        d= gcd(dx,dy) 
        return dy//d,dx//d
    
    if len(points)<=1: return len(points), None 
    
    max_pnt =0 
    best_line = None
    
    for i,p1 in enumerate(points):
        slopes = defaultdict(int)
        duplicates = 1
        for j,p2 in enumerate(points):
            if i==j: continue
            elif p1 ==p2: duplicates +=1
            else:
                slope = find_slop(p1,p2)
                slopes[slope]+=1
        current_max = max(slopes.values(),default=0)+duplicates
        if current_max>max_pnt:
            max_pnt = current_max
            most_common_slope = max(slopes,key = slopes.get,default = None) 
            if most_common_slope is None:
                m= most_common_slope[0]/most_common_slope[1] if most_common_slope[1]!=0 else None
                b = p1[1] - m*p1[0] if m is not None else None
                best_line = (m,b)
    return max_pnt, best_line
    
n= int(input())
points=[]
for i in range(n):
    x, y = map(int, input().split(" "))
    points.append((x, y))

result = max_pnt_on_line(points)

print(f"y = {result[1][0]:.2f}x + {result[1][1]:.2f}"if result[1][0] is not None else f"x = {points[0][0]}")
print(result[0])