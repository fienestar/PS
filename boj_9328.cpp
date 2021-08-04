/*
    열쇠
    https://www.acmicpc.net/problem/9328
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	size_t h, w;
	cin >> h >> w;

	vector<string> m(h);
	for (auto& line : m)
		cin >> line;

	list<pair<size_t, size_t>> doors['Z' - 'A' + 1];
	bool has_key['Z' - 'A' + 1] = {};

	string keys;
	cin >> keys;

	if(keys != "0")
		for (auto key : keys)
			has_key[key - 'a'] = true;

	size_t $ = 0;

	function<void(size_t, size_t)> dfs = [&](size_t i, size_t j) {
		char& c = m[i][j];

		if (c == '$')
			++$;
		else if (isalpha(c)) {
			bool is_key = c >= 'a';
			char id = (c | 32) - 'a';

			if (is_key) {
				if (!has_key[id]) {
					c = '*';

					for (auto& [x, y] : doors[id]) {
						m[x][y] = '.';
						dfs(x, y);
					}
				}
				has_key[id] = true;
			}
			else if (not has_key[id]) {
				doors[id].emplace_back(i, j);
				return;
			}
		}

		c = '*';

		static int di[] = { 1,-1,0,0 };
		static int dj[] = { 0,0,1,-1 };
		for (size_t k = 0; k != 4; ++k) {
			size_t mi = i + di[k];
			size_t mj = j + dj[k];

			if (mi >= h || mj >= w)continue;
			if (m[mi][mj] == '*')continue;

			dfs(mi, mj);
		}
	};


	for (size_t i = 0; i != h; ++i) {
		if (m[i][0] != '*')dfs(i, 0);
		if (m[i][w - 1] != '*')dfs(i, w - 1);
	}

	for (size_t j = 0; j != w; ++j) {
		if (m[0][j] != '*')dfs(0, j);
		if (m[h - 1][j] != '*')dfs(h - 1, j);
	}

	cout << $ << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t T;
	cin >> T;

	while (T--)solve();
}