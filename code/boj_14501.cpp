/*
    퇴사
    https://www.acmicpc.net/problem/14501
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    size_t N;
    cin >> N;

    size_t ans = 0;
    vector<size_t> max_p(N+1);
    for(size_t i=0; i!=N; ++i){
        size_t t, p;
        cin >> t >> p;

        max_p[i+1] = max(max_p[i+1], max_p[i]);

        if(i+t > N) continue;

        max_p[i+t] = max(max_p[i+t], max_p[i] + p);
        ans = max(ans, max_p[i+t]);
    }

    cout << ans;
}