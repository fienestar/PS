'''
    소수
    https://www.acmicpc.net/problem/1312
'''
a,b,n=map(int,input().split())
print(a*10**n//b%10)