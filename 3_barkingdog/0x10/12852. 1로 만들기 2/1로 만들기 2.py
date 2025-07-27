n = int(input())

d= [0] * (n+1)
path = [0] * (n+1)

for i in range(2, n+1):
    d[i] = d[i-1]+1
    path[i] = i - 1
    
    if i%2==0 and d[i//2]+1 < d[i]:
        d[i]= d[i//2]+1
        path[i] = i//2
    if i%3==0 and d[i//3]+1 < d[i]:
        d[i]= d[i//3]+1
        path[i] = i//3
print(d[n])

idx=n
while idx>=1:
    print(idx, end=' ')
    idx=path[idx]    