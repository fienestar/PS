'''
    음계
    https://www.acmicpc.net/problem/2920
'''
l=input()
if l == ' '.join(map(str,range(1,9))):
	print('ascending')
elif l == ' '.join(map(str,range(1,9)[-1::-1])):
	print('descending')
else:
	print('mixed')