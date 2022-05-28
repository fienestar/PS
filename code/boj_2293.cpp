/*
    동전 1
    https://www.acmicpc.net/problem/2293
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for(auto& coin:coins)
		cin >> coin;

	static int ans[2][10001] = {};
	size_t b = 0;
	ans[b][0] = 1;

	for(size_t i=0; i!=N; ++i){
		auto& from = ans[b];
		auto& cur = ans[b^=1];

		memset(cur, 0, sizeof(cur));

		for(int k=0; k<=K; ++k)
			for(int j=0; k+j*coins[i]<=K; ++j)
				cur[k+j*coins[i]] += from[k];
	}

	cout << ans[b][K];
}