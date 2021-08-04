'''
    알람 시계
    https://www.acmicpc.net/problem/2884
'''
a,b=map(int,input().split())
c=(a*60+b-45+24*60)%(24*60)
print(c//60,c%60)