/*
    연속합
    https://www.acmicpc.net/problem/1912
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
    static int s[100001];
    int min,max;
    size_t N;
    cin >> N ;
    min = s[0] = 0; max=-2147483648;
    loop(i,N){
	cin >> s[i+1];
	s[i+1]+=s[i];
        if(max < s[i+1]-min) max = s[i+1] - min;
	if(s[i+1] < min) min = s[i+1];
    }
    cout << max;
}