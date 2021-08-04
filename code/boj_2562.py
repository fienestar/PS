'''
    최댓값
    https://www.acmicpc.net/problem/2562
'''
print("\n".join(map(str,max([(int(input()),i+1) for i in range(9)]))))