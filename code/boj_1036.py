'''
    36진수
    https://www.acmicpc.net/problem/1036
'''
N = int(input())
n2s = [None]*36
s2n = {}

for i in range(10):
  n2s[i] = chr(48+i)
  s2n[chr(48+i)] = i

for i in range(26):
  n2s[10+i] = chr(65+i)
  s2n[chr(65+i)] = 10+i

count = [0]*36
for _ in range(N):
  s = input()
  k = 1
  for i in range(len(s)):
    count[s2n[s[len(s)-i-1]]] += k
    k *= 36

idx = list(range(36))
idx.sort(key=lambda i: -count[i]*(35-i))

K = int(input())
sum = 0

for i in range(K):
  sum += count[idx[i]] * 35;
for i in range(K,36):
  sum += count[idx[i]] * idx[i];

s = ""
while True:
  s += n2s[sum%36]
  sum //= 36
  if sum == 0: break

print(s[::-1])