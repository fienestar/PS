/*
    가장 큰 정사각형
    https://www.acmicpc.net/problem/1915
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m));
    int M = 0;
    for(size_t i=0; i!=n; ++i)
        for(size_t j=0; j!=m; ++j){
            char c;
            cin >> c;
            dp[i][j] = c - '0';

            if(i&&j)
                dp[i][j] *= min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + 1;

            M = max(M, dp[i][j]);
        }

    cout << M*M;
}