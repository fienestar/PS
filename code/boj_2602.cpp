/*
    돌다리 건너기
    https://www.acmicpc.net/problem/2602
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Code here!
    string magic;
    string angdev[2];
    static size_t count[2][21];
    cin >> magic >> angdev[0] >> angdev[1];
    size_t N = angdev[0].size();
    size_t M = magic.size();
    for(size_t i=0;i!=N;++i)
    {
        size_t lazy_count[2][21] = {};

        for(size_t j=0;j!=2;++j)
            for(size_t k=0;k!=M;++k)
                if(angdev[j][i] == magic[k])
                    lazy_count[!j][k+1] += count[j][k] + (k==0);

        for(size_t j=0;j!=2;++j)
            for(size_t k=0;k<=M;++k)
                count[j][k]+=lazy_count[j][k];
    }
    cout << count[0][M] + count[1][M];
}