MOD = 1000000009
MAX_N = 1000000

dp = [0] * (MAX_N + 1)
dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, MAX_N + 1):
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD

T = int(input())
for _ in range(T):
    n = int(input())
    print(dp[n])