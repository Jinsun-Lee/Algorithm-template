n = int(input())
L = list(map(int, input().split()))
J = list(map(int, input().split()))    

joy = 0

def dp(cnt, energy, sum, L, J):
    global joy

    if cnt == n:
        joy = max(joy, sum)
        return

    if energy - L[cnt] > 0:
        dp(cnt+1, energy - L[cnt], sum + J[cnt], L, J)
    
    dp(cnt+1, energy, sum, L, J)

dp(0, 100, 0, L, J)
print(joy)