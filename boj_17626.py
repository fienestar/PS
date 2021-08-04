'''
    Four Squares
    https://www.acmicpc.net/problem/17626
'''
import math

def f(i, m, s):
    if m == 0: return 0
    if i == 3: return 1
    sq = int(math.sqrt(m))
    ans = 4
    for k in range(1, min(sq+1,s+1)):
        ans = min(ans, f(i+1, m - k*k, k)+1)
    return ans
n = int(input())
print(f(0, n, n))