/*
    RGB거리
    https://www.acmicpc.net/problem/1149
*/
#include <bits/stdc++.h>

#define all(c) begin(c),end(c)

using namespace std;

int main()
{
    size_t cost[2][3]={};
    size_t N;
    cin >> N;
    for(size_t i=0;i!=N;++i)
        for(size_t j=0;j!=3;++j){
            cin >> cost[~i&1][j];
            cost[~i&1][j] += min(cost[i&1][(j+1)%3],cost[i&1][(j+2)%3]);
        }
    sort(all(cost[N&1]));
    cout << cost[N&1][0];
}