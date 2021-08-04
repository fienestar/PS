/*
    외판원 순회
    https://www.acmicpc.net/problem/2098
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	vector<vector<size_t>> dist(N, vector<size_t>(N));
	for(auto& line:dist)
		for(auto& e:line)
			cin >> e;

	size_t total_cost = 0;
	size_t visited_count = 0;
	size_t visited = 0;
	static size_t dfs_visited[16 * (1 << 16)] = {};

	function<size_t(size_t)> dfs = [&](size_t n)->size_t {
		if(visited_count == N && n == 0)
			return 0;

		size_t& min_cost = dfs_visited[n << 16 | visited];

		if(min_cost)
			return min_cost;

		min_cost = 0x3f3f3f3f;

		for(size_t i=0; i!=N; ++i)
			if(dist[n][i] != 0 && not (visited & (1 << i))){
				visited ^= 1 << i;
				++visited_count;
				min_cost = min(min_cost, dfs(i) + dist[n][i]);
				--visited_count;
				visited ^= 1 << i;
			}

		return min_cost;
	};

	cout << dfs(0);
}