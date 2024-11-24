import math
from collections import defaultdict

class Line:
    def __init__(self, m, c, is_vertical):
        self.m = m
        self.c = c
        self.is_vertical = is_vertical

    def __eq__(self, other):
        return (math.isclose(self.m, other.m, abs_tol=1e-9) and math.isclose(self.c, other.c, abs_tol=1e-9) and self.is_vertical == other.is_vertical)

    def __hash__(self):
        return hash((self.m, self.c, self.is_vertical))

def find_max_points_line(points):
    n = len(points)
    ans = None
    max_count = 0

    for i in range(n):
        line_map = defaultdict(int)
        for j in range(i + 1, n):
            x1, y1 = points[i]
            x2, y2 = points[j]

            if x1 == x2:l = Line(float('inf'), x1, True)
            else:  # Non-vertical line
                m = (y2 - y1) / (x2 - x1)
                c = y1 - m * x1
                l = Line(m, c, False)

            line_map[l] += 1

            if line_map[l] > max_count:
                ans = l
                max_count = line_map[l]

    return ans, max_count + 1  # +1 to include the starting point

n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append((x, y))

ans, max_points = find_max_points_line(points)

if ans.is_vertical:print(f"x = {ans.c:.2f}")
else:print(f"y = {ans.m:.2f}x + {ans.c:.2f}")
print(max_points)

