n, m = map(int, input().split()) 
r, c, d = map(int, input().split()) 
grid = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
cnt = 0

while True:
    
    if grid[r][c] == 0:
        grid[r][c] = -1
        cnt += 1
    
    for _ in range(4):
        d = (d+3) % 4
        nr = r + dx[d]
        nc = c + dy[d]
        
        if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 0:
            r, c = nr, nc
            break
     
    else:
        nr = r - dx[d]
        nc = c - dy[d]
        
        if not (0 <= nr < n and 0 <= nc < m and grid[nr][nc] != 1):
            break
        r, c = nr, nc
        
print(cnt)                