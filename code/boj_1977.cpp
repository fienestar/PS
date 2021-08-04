/*
    완전제곱수
    https://www.acmicpc.net/problem/1977
*/
// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t M,N;
    cin >> M >> N;
    
    size_t i=sqrt(M),min,sum=0;
    while(i*i<M)++i;
    if(i*i>N){
        cout << -1;
        return 0;
    }
    min = i*i;
    for(;i*i<=N;++i)sum+=i*i;
    cout << sum << "\n" << min;
}