'''
    뚊
    https://www.acmicpc.net/problem/11383
'''
o=input
print('Not '*any(o()!=''.join(c*2for c in k)for k in eval("o(),"*int(o()[:2])))+'Eyfa')