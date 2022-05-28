/*
    LCM(1, 2, ..., n)
    https://www.acmicpc.net/problem/11690
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	ull n;
	cin >> n;

	vector<bool> mark(n+1);
	uint32_t ans = 1;
	for(ull i=2; i<=n; ++i)
		if(!mark[i]){
			ull j;
			for(j=i; j<=n; j*=i);
			ans *= j/i;

			mark[i] = 1;
			for(j=i*i; j<=n; j+=i)
				mark[j] = 1;
		}

	cout << ans;
}