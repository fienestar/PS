/*
    너 봄에는 캡사이신이 맛있단다
    https://www.acmicpc.net/problem/15824
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
enum{ MOD = 1'000'000'007 };

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<ull> v(N);
	for(auto& c:v)
		cin >> c;

	sort(v.rbegin(), v.rend());

	ull v2 = 2;
	ull vsum = v[0];
	ull sum = 0;
	for(size_t i=1; i!=v.size(); ++i){
		sum = (sum + vsum - v[i] * (v2-1) % MOD + MOD) % MOD;
		vsum = vsum * 2 % MOD;
		v2 = (v2 * 2) % MOD;

		vsum = (vsum + v[i]) % MOD;
	}

	cout << sum;
}