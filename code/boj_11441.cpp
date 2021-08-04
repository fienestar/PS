/*
    합 구하기
    https://www.acmicpc.net/problem/11441
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
    int S[100002] = {0};
    size_t N,A,B;
    cin >> N;
    loop(i,N){
        cin>>S[i+1];
        S[i+1]+=S[i];
    }
    cin >> N;
    while(N--){
	cin >> A >> B;
        cout << S[B] - S[A-1] << "\n";
    }
}