'''
    곰곰이와 자판기
    https://www.acmicpc.net/problem/25200
'''
N,M=map(int,input().split())
values = []
for i in range(N):
  node = [i, None]
  values.append([node,node])

for _ in range(M):
  u, v = map(int,input().split())
  u -= 1
  v -= 1

  if values[u][0] == None: continue
  if values[v][0] != None:
    values[u][1][1] = values[v][0]
    values[u] = [values[u][0], values[v][1]]

  values[v] = values[u]
  values[u] = [None, None]

result = [0]*N
for i in range(N):
  it = values[i][0]
  while it != None:
    result[it[0]] = i+1
    it = it[1]

print(*result)