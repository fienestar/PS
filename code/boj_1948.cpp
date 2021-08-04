/*
    임계경로
    https://www.acmicpc.net/problem/1948
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	using ull = unsigned long long;
	vector<list<pair<size_t, ull>>> E(N);
	while(M--){
		size_t s, d;
		ull c;

		cin >> s >> d >> c;
		--s; --d;

		E[s].emplace_back(d, c);
	}

	size_t s, d;
	cin >> s >> d;
	--s; --d;

	vector<ull> cost(N);
	function<ull(size_t)> cost_of = [&](size_t v){
		if(cost[v])
			return cost[v];

		cost[v] = 0;
		for(auto& e:E[v])
			cost[v] = max(cost[v], cost_of(e.first) + e.second);

		return cost[v];
	};

	cout << cost_of(s) << "\n";

	queue<size_t> q;
	vector<bool> visited(N, false);

	q.emplace(s);
	visited[s] = true;

	ull count = 0;
	while(!q.empty()){
		size_t v = q.front();
		q.pop();

		for(auto& e:E[v])
			if(cost[v] == cost[e.first] + e.second){
				++count;

				if(not visited[e.first]){
					visited[e.first] = true;
					q.emplace(e.first);
				}
			}
	}

	cout << count;
}