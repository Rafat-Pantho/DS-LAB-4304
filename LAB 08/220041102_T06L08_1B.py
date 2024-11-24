from collections import defaultdict

t,m,n = map(int,input().split())
maze_map = defaultdict(list)

for i in range(t):
    student_name = input()
    maze=[]
    for j in range(m):maze.append(input().strip())
    maze_key = tuple(maze)
    maze_map[maze_key].append(student_name)

for mze_key, students in maze_map.items():
    print(' '.join(str(i) for i in students))