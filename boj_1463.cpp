/*
    1로 만들기
    https://www.acmicpc.net/problem/1463
*/
// 사용된 알고리즘: 
// R: X
// T: 0

#include <bits/stdc++.h>

using namespace std;

#ifndef LOCAL
#define LOCAL(x) ((void)0)
#endif
#define endl "\n"
#define elif else if
#define ifn(v) if(v);else
#define elifn(v) else ifn(v)

size_t DP[3'000'000];

void seet(size_t idx,size_t value)
{
    if(!DP[idx])DP[idx]=value;
    else DP[idx]=min(DP[idx],value);
}

int main()
{
    //LOCAL(OUTPUT_TO_FILE);
    //LOCAL(INPUT_FROM_FILE);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    cin >> N;
    
    for(size_t i=1;i!=N;++i){
        seet(i+1,DP[i]+1);
        seet(i*2,DP[i]+1);
        seet(i*3,DP[i]+1);
    }
    
    cout << DP[N];
}