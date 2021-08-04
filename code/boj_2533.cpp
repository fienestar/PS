/*
    사회망 서비스(SNS)
    https://www.acmicpc.net/problem/2533
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<list<size_t>> E(N);
	for(size_t i=1; i!=N; ++i){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		E[a].push_back(b);
		E[b].push_back(a);
	}

	using cost_t = pair<size_t, size_t>;
	vector<int> is_visited(N, false);

	function<cost_t(size_t)> dfs = [&](size_t v)->cost_t{
		cost_t result = {1,0};
		is_visited[v] = true;

		for(auto next:E[v])
			if(!is_visited[next]){
				auto cost = dfs(next);

				result.first += min(cost.first, cost.second);
				result.second += cost.first;
			}

		return result;
	};

	auto cost = dfs(0);
	cout << min(cost.first, cost.second);
}