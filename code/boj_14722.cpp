/*
    우유 도시
    https://www.acmicpc.net/problem/14722
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    size_t N;
    cin >> N;

    vector<vector<pair<int,int>>> v(N);
    for(size_t i=0;i!=N;++i){
        v[i].resize(N,{0,0});

        for(size_t j=0;j!=N;++j){
            size_t type;
            cin >> type;

#define update_max(a,b) (a.second >= b.second ? a : (a=b))
            if(i)update_max(v[i][j],v[i-1][j]);
            if(j)update_max(v[i][j],v[i][j-1]);
            if(v[i][j].first == type){
                ++v[i][j].first;
                v[i][j].first%=3;
                ++v[i][j].second;
            }
        }
    }
    cout << v[N-1][N-1].second;
}