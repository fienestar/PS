/*
    정점들의 거리
    https://www.acmicpc.net/problem/1761
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<list<pair<size_t, size_t>>> E(N);
	for(size_t i=1; i!=N; ++i){
		size_t a, b, c;
		cin >> a >> b >> c;
		--a; --b;

		E[a].emplace_back(b, c);
		E[b].emplace_back(a, c);
	}

	vector<size_t> height(N, -1);
	vector<size_t> parent(N, -1);
	vector<size_t> parent_dist(N, -1);

	function<size_t(size_t)> calc_height = [&](size_t v){
		height[v] = 0;

		for(auto& e:E[v])if(parent[e.first] == -1){
			parent[e.first] = v;
			parent_dist[e.first] = e.second;
			height[v] = max(height[v], calc_height(e.first) + e.second);
		}

		return height[v];
	};

	parent[0] = 0;
	calc_height(0);

	size_t M;
	cin >> M;
	while(M--){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		size_t dist = 0;
		while(a != b){
			while(height[a] < height[b]){
				dist += parent_dist[a];
				a = parent[a];
			}

			if(height[a] == height[b] && a != b){
				dist += parent_dist[a];
				a = parent[a];
			}

			swap(a,b);
		}
		cout << dist << "\n";
	}
}