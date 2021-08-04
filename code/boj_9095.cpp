/*
    1, 2, 3 더하기
    https://www.acmicpc.net/problem/9095
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
    size_t T,N;
    size_t count[12] = {};
    cin >> T;

    count[1]=count[2]=count[3]=1;

    for(size_t i=2;i!=11;++i)
        for(size_t j=1;j!=4&&i-j;++j)
            count[i]+=count[i-j];
    
    while(T--){
        cin >> N;
        cout << count[N] << "\n";
    }
}