/*
    DFS와 BFS
    https://www.acmicpc.net/problem/1260
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, M, V;
	cin >> N >> M >> V;
	--V;

	vector<vector<size_t>> E(N);
	while(M--){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		E[a].push_back(b);
		E[b].push_back(a);
	}

	for(auto& e:E)
		sort(e.begin(), e.end());

	vector<uint8_t> visited(N);
	function<void(size_t)> visit = [&](size_t V){
		visited[V] = true;
		cout << V+1 << " ";

		for(auto& next:E[V])
			if(!visited[next])
				visit(next);
	};

	visit(V);
	cout << "\n";

	visited = vector<uint8_t>(N);
	queue<size_t> q;
	q.push(V);
	visited[V] = true;
	while(!q.empty()){
		auto V = q.front();
		q.pop();

		cout << V+1 << " ";
		for(auto& next:E[V])
			if(!visited[next]){
				q.push(next);
				visited[next] = true;
			}
	}
}