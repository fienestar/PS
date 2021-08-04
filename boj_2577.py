'''
    숫자의 개수
    https://www.acmicpc.net/problem/2577
'''
a,b,c=[int(input()) for i in range(3)]
s=str(a*b*c)
for i in range(0,10):
	print(s.count(str(i)))