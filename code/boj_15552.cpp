/*
    빠른 A+B
    https://www.acmicpc.net/problem/15552
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,N) for(::std::size_t i=0;i!=N;++i)
#define sloop(i,String) for(::std::size_t i=0;String[i];++i)
#define rloop(i,N) for(::std::size_t i=N;i--;)
#define all(v) v.begin(),v.end()

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t T,A,B;
    cin >> T;
    while(T--){
	cin >> A >> B;
	cout << A + B << "\n";
    }
}