/*
    합성함수와 쿼리
    https://www.acmicpc.net/problem/17435
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t m;
	cin >> m;

	vector<vector<size_t>> f(19, vector<size_t>(m));
	for (auto& y : f[0]) {
		cin >> y;
		--y;
	}

	for (size_t i = 1; i != 19; ++i)
		for (size_t j = 0; j != m; ++j)
			f[i][j] = f[i - 1][f[i - 1][j]];

	size_t Q;
	cin >> Q;
	while (Q--) {
		size_t n, x;
		cin >> n >> x;

		--x;
		for (size_t i = 19; i--;)
			if (n & (1 << i))
				x = f[i][x];

		cout << x + 1 << "\n";
	}
}