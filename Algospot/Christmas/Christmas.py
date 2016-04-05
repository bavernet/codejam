# problem: https://algospot.com/judge/problem/read/CHRISTMAS
# hint: math, dp, partial sum
# level: moderate
from sys import stdin

def mod(n):
    return n % 20091101

def comb(n):
    return mod(n * (n - 1) / 2)

def getPartialSum(dolls, k):
    s = [0] * len(dolls)
    for i, d in enumerate(dolls):
        s[i] = (s[i-1] + d) % k
    return s

def solve1(ps, k):
    cnt = [1] + [0] * (k - 1)
    for s in ps:
        cnt[s] += 1
    ans = 0
    for c in cnt:
        ans = mod(ans + comb(c))
    return ans

def solve2(ps, k):
    n = len(ps)
    prev = [0] + [-1] * k
    dp = [0] * (n + 1) + [-1]
    for i, s in enumerate(ps, 1):
        dp[i] = max(dp[i-1], dp[prev[s]] + 1)
        prev[s] = i
    return dp[n]

if __name__ == '__main__':
    nTests = int(stdin.readline())
    while nTests:
        nTests -= 1
        n, k = map(int, stdin.readline().split())
        d = map(int, stdin.readline().split())
        ps = getPartialSum(d, k)
        print solve1(ps, k), solve2(ps, k)
