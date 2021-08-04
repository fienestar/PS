'''
    OX퀴즈
    https://www.acmicpc.net/problem/8958
'''
for i in range(int(input())):
	m = list(map(lambda v:v=='O',input()))
	result = +m[0]
	for j in range(1,int(len(m))):
		if m[j] != 0:
			m[j] += m[j-1]
		result += m[j]
	print(result)