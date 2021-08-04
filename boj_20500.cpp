/*
    Ezreal 여눈부터 가네 ㅈㅈ
    https://www.acmicpc.net/problem/20500
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	if(N <= 1){ cout << "0"; return 0; }
	else if(N<=2){ cout << "1"; return 0; }

	N -= 3;

	using ull = unsigned long long;
	ull dp[3] = {0,1,1};
	ull mod = 1000000007;
	size_t i=2;

	while(N--){
		++i;
		i%=3;
		dp[i%3] = (dp[(i+2)%3] + dp[(i+1)%3] * 2) % mod;
	}

	cout << dp[i];
}