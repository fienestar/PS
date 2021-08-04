/*
    평균 점수
    https://www.acmicpc.net/problem/10039
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
    size_t S=0,T;
    loop(i,5){
        cin >> T;
	if(T < 40)T=40;
	S+=T;
    }
    cout << S / 5;
}