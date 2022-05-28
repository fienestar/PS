/*
    곰곰이의 심부름
    https://www.acmicpc.net/problem/25198
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N,S,C,H;
	cin >> N >> S >> C >> H;
	--S; --C; --H;

	vector<list<size_t>> E(N);
	for(size_t i=1; i!=N; ++i){
		size_t u, v;
		cin >> u >> v;
		--u; --v;

		E[u].push_back(v);
		E[v].push_back(u);
	}

	vector<size_t> depth(N);
	vector<size_t> path;
	function<void(size_t)> make_path = [&](size_t u)->void{
		path.push_back(u);
		if(depth[u] == 1) return;
		for(auto& v:E[u])
			if(depth[v] < depth[u])
				return make_path(v);
	};

	function<void(size_t)> dfs = [&](size_t u){
		for(auto v:E[u])
			if(!depth[v]){
				depth[v] = depth[u] + 1;
				dfs(v);
			}
	};
	depth[S] = 1;
	dfs(S);
	make_path(C);

	reverse(begin(path),end(path));
	path.pop_back();
	size_t mid = path.size();

	depth = vector<size_t>(N);
	depth[C] = 1;
	dfs(C);
	make_path(H);
	reverse(begin(path)+mid,end(path));

	vector<uint8_t> has(N);
	vector<size_t> unique_count(path.size()+1);
	for(size_t i=path.size(); i--;){
		unique_count[i] = unique_count[i+1] + !has[path[i]];
		has[path[i]] = true;
	}

	has = vector<uint8_t>(N);
	size_t count = 0;
	for(size_t i=0; i!=path.size(); ++i){
		auto c = path[i];
		if(!has[c])
			count += unique_count[i]-1;
		has[c] = true;
	}

	cout << count;
}