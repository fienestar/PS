/*
    소형기관차
    https://www.acmicpc.net/problem/2616
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<size_t> sum(n+1);
    for(size_t i=1; i<=n; ++i){
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    size_t k;
    cin >> k;

    vector<vector<size_t>> m(4, vector<size_t>(n+1));
    size_t ans = 0;
    for(size_t i=1; i<=3; ++i)
        for(size_t j=k; j<=n; ++j){
            m[i][j] = max(m[i][j-1],m[i-1][j-k]+sum[j]-sum[j-k]);
            ans = max(ans, m[i][j]);
        }

    cout << ans;
}