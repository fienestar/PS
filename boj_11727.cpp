/*
    2×n 타일링 2
    https://www.acmicpc.net/problem/11727
*/
// 사용된 알고리즘: dp
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

enum{
    MOD=10007
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t dp[1000];
    size_t n;
    cin>>n;
    dp[0]=dp[1]=1;
    for(size_t i=2;i<=n;++i){
        dp[i]=(dp[i-1]+dp[i-2]*2)%MOD;
    }
    cout << dp[n];
}