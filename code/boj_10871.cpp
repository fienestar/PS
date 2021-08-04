/*
    X보다 작은 수
    https://www.acmicpc.net/problem/10871
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
    size_t N,X,D;
    cin >> N >> X;
    while(N--){ cin >> D; if(D<X)cout << D << " "; }
}