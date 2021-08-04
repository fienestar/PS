'''
    통계학
    https://www.acmicpc.net/problem/2108
'''
data = [int(input()) for _ in range(int(input()))]
data.sort()
print(round(sum(data)/len(data)))
print(data[len(data)//2])

freq = {}
for x in data:
	if x in freq:
		freq[x] += 1
	else:
		freq[x] = 1

freql = list(freq.items())
freql.sort(key=lambda x:(x[1],-x[0]))
if not len(freql) == 1 and freql[-1][1] == freql[-2][1]:
	print(freql[-2][0])
else:
	print(freql[-1][0])

print(max(data) - min(data))