/*
    노드사이의 거리
    https://www.acmicpc.net/problem/1240
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<list<pair<size_t,size_t>>> E(10001);
	for(size_t i=N; --i;){
		size_t a, b, c;
		cin >> a >> b >> c;

		E[a].emplace_back(b, c);
		E[b].emplace_back(a, c);
	}

	size_t end = -1;
	bool visited[10001];
	function<size_t(size_t)> dfs = [&](size_t v)->size_t{
		visited[v] = true;

		if(v == end)
			return 0;

		for(auto [next, cost]:E[v])
			if(size_t result; !visited[next] && (result = dfs(next)) != -1)
				return result + cost;

		return -1;
	};

	while(M--){
		size_t a, b;
		cin >> a >> b;

		end = b;
		memset(visited, false, sizeof(visited));
		cout << dfs(a) << "\n";
	}
}