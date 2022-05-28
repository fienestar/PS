/*
    Jogging
    https://www.acmicpc.net/problem/21211
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t I, S, L, U;
	cin >> I >> S >> L >> U;
 
	using edge_t = tuple<size_t, size_t, size_t>;
	vector<list<edge_t>> E(I);
	size_t E_index = 0;
	for (size_t i = 0; i != S; ++i) {
		size_t u, v, cost;
		cin >> u >> v >> cost;
		E[u].emplace_back(i, cost * 2, v);
		E[v].emplace_back(i, cost * 2, u);
	}
 
	vector<size_t> dist(I, -1);
 
	dist[0] = 0;
 
	priority_queue<pair<size_t,size_t>> pq;
	pq.emplace(0, 0);
 
	while (!pq.empty()) {
		auto [c, v] = pq.top();
		pq.pop();
 
		for(auto& [index, cost, next]:E[v])
			if (dist[next] > dist[v] + cost) {
				dist[next] = dist[v] + cost;
				pq.emplace(cost, next);
			}
	}
 
	size_t ans = 0;
	vector<uint8_t> visited_edge(S, false);
	for(size_t i=0; i!=I; ++i)
		if(dist[i] < U)
			for(auto& [index, cost, next]:E[i])
				if (!visited_edge[index]) {
					visited_edge[index] = true;
					++ans;
				}
 
	cout << ans;
}