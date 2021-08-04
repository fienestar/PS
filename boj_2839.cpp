/*
    설탕 배달
    https://www.acmicpc.net/problem/2839
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
    int N;
    cin >> N;
    for(int i=N;i>=0;i-=3)
	if(i%5==0){
	    cout << (N-i)/3 + i/5;
	    return 0;
	}
    cout << -1;
}