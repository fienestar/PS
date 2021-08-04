/*
    열 개씩 끊어 출력하기
    https://www.acmicpc.net/problem/11721
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
    char buf[101];
    size_t i,j;
    cin >> buf;
    sloop(i,buf){
        cout << buf[i];
        if(!((i+1)%10))cout << "\n";
    }
}