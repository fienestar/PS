/*
    핑크 플로이드
    https://www.acmicpc.net/problem/6091
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	priority_queue<pair<int,pair<size_t,size_t>>> pq;
	for(size_t i=0; i!=N; ++i)
		for(size_t j=i+1; j!=N; ++j){
			int cost;
			cin >> cost;
			pq.emplace(-cost, make_pair(i,j));
		}

	vector<size_t> parent(N);
	for(size_t i=0; i!=N; ++i)
		parent[i] = i;

	function<size_t(size_t)> get = [&](size_t v){
		if(parent[v] == v)
			return v;
		else
			return parent[v] = get(parent[v]);
	};

	vector<vector<size_t>> adj(N);
	while(!pq.empty()){
		auto[cost, edge] = pq.top();
		auto[a,b] = edge;
		pq.pop();

		auto p_a = get(a);
		auto p_b = get(b);
		if(p_a != p_b){
			parent[p_a] = p_b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}

	for(auto& adjl:adj){
		sort(adjl.begin(), adjl.end());
		cout << adjl.size() << " ";
		for(auto& v:adjl)
			cout << v+1 << " ";
		cout << "\n";
	}
}