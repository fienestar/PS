/*
    이항 계수 3
    https://www.acmicpc.net/problem/11401
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
enum: ull{ MOD = 1'000'000'007 };

ull pow(ull base, ull exp)
{
	ull result = 1;
	while(exp){
		if(exp&1){
			result *= base;
			result %= MOD;
		}

		base *= base;
		base %= MOD;
		exp >>= 1;
	}

	return result;
}

int main()
{
	static ull f[4'000'001] = {1};
	for(ull i=1; i!=4'000'001; ++i)
		f[i] = f[i-1]*i % MOD;

	ull n, r;
	cin >> n >> r;

	cout << f[n] * pow(f[r] * f[n-r] % MOD, MOD-2) % MOD;
}