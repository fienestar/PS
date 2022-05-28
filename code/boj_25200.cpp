/*
    곰곰이와 자판기
    https://www.acmicpc.net/problem/25200
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> value(N);
	vector<size_t> parent(N);
	vector<size_t> index(N);
	for(size_t i=0; i!=N; ++i) index[i] = value[i] = parent[i] = i;
	function<size_t(size_t)> root = [&](size_t n){
		if(parent[n] == n) return n;
		return parent[n] = root(parent[n]);
	};

	auto merge = [&](size_t u, size_t v){
		if(index[u] == -1) return;

		size_t before = u;
		u = root(index[u]);
		index[before] = -1;
		value[u] = v;
		if(index[v] == -1)
			index[v] = u;
		else
			parent[u] = root(index[v]);
	};

	size_t M;
	cin >> M;
	while(M--){
		size_t u, v;
		cin >> u >> v;
		--u; --v;

		merge(u, v);
	}

	for(size_t i=0; i!=N; ++i)
		cout << value[root(i)]+1 << " ";
}