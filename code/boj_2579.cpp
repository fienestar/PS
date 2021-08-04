/*
    계단 오르기
    https://www.acmicpc.net/problem/2579
*/
// 사용된 알고리즘: DP
// R:

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif

int main()
{
    LOCAL(OUTPUT_TO_FILE);
    LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    size_t score[512] = {};
    size_t score_max[512] = {};
    cin >> N;

    for(size_t i=1;i<=N;++i)
        cin >> score[i];
    
    score_max[0] = 0;
    score_max[1] = score[1];
    score_max[2] = score[1] + score[2];

    for(size_t i=3;i<=N;++i)
        score_max[i] = max({
            score_max[i-3] + score[i-1],
            score_max[i-2]
        }) + score[i];

    cout << score_max[N];
}