/*
    합
    https://www.acmicpc.net/problem/8393
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define loop(i,N) for(::std::size_t i=0;i!=N;++i)
#define sloop(i,String) for(::std::size_t i=0;String[i];++i)
#define rloop(i,N) for(::std::size_t i=N;i--;)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t N;
    cin >> N;
    cout << ((N * (N+1)) >> 1);
}