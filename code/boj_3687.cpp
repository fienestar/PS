/*
    성냥개비
    https://www.acmicpc.net/problem/3687
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

void solve()
{
	size_t N;
	cin >> N;

	function<ull(size_t,bool)> dfs = [&](size_t n, bool is_root) -> ull{
		if(n == 0)
			return 0;

		static ull memo[101] = {0, 0, 1, 7, 4, 2, 6, 8, 10};
		auto& res = memo[n];
		if(res)return res;
		res = -1;

		static size_t cost[] = { 6,2,5,5,4,5,6,3,7,6 };
		for(size_t j=!is_root; j!=10; ++j)
			res = min(res, dfs(n-cost[j], false)*10 + j);

		return res;
	};

	cout << dfs(N, true) << " ";

	if(N&1){ cout << "7"; N-=3; }
	N >>= 1;
	while(N--)cout << "1";
	cout << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t T;
	cin >> T;

	while(T--)
		solve();
}