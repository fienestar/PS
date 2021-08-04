/*
    나머지
    https://www.acmicpc.net/problem/10430
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
    size_t A,B,C;
    cin >> A >> B >> C;
    cout << (A+B)%C << "\n" << (A+B)%C << "\n" << (A*B)%C << "\n" << (A*B)%C;
}