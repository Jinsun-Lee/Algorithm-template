dp = [[0 for _ in range(31)] for _ in range(31) ]

for j in range(1, 31):
    dp[0][j] = 1

for i in range(1,31):
    for j in range(30):
        if j == 0:
            dp[i][j] = dp[i-1][j+1]
        else:
            dp[i][j] = dp[i-1][j+1] + dp[i][j-1]

while 1:
    n = int(input())
    if n == 0:
        break
    print(dp[n][0])