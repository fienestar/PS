/*
    Emails
    https://www.acmicpc.net/problem/21216
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<list<size_t>> E(N);
	for(size_t i=M; i--;){
		size_t u, v;
		cin >> u >> v;
		--u; --v;

		E[u].push_back(v);
		E[v].push_back(u);
	}

	vector<size_t> dist(N);
	queue<size_t> q;
	size_t visited_count = 1;
	size_t max_dist = 0;
	q.push(0);

	while(!q.empty()){
		auto u = q.front();
		q.pop();

		for(auto v:E[u])
			if(v && !dist[v]){
				++visited_count;
				max_dist = max(max_dist, dist[v]=dist[u]+1);
				q.push(v);
			}
	}

	if(visited_count < N)
		cout << "-1";
	else
		cout << 1+(size_t)ceil(log2(max_dist));
}