/*
    트리의 부모 찾기
    https://www.acmicpc.net/problem/11725
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<list<size_t>> E(N+1);
	for(size_t i=N; --i; ){
		size_t a, b;
		cin >> a >> b;

		E[a].push_back(b);
		E[b].push_back(a);
	}

	vector<size_t> parent(N+1);
	queue<size_t> q;
	parent[1] = 1;
	q.push(1);

	while(!q.empty()){
		auto v = q.front();
		q.pop();

		for(auto next:E[v])
			if(!parent[next]){
				parent[next] = v;
				q.push(next);
			}
	}

	for(size_t i=2; i<=N; ++i)
		cout << parent[i] << "\n";
}