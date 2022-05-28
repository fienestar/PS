/*
    Yes or yes
    https://www.acmicpc.net/problem/25195
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<list<size_t>> E(N);
	while(M--){
		size_t u, v;
		cin >> u >> v;
		--u; --v;

		E[u].push_back(v);
	}

	size_t S;
	cin >> S;

	vector<uint8_t> has(N);
	while(S--) { size_t s; cin >> s; has[--s] = true; }

	function<bool(size_t)> dfs = [&](size_t u){
		if(has[u]) return false;

		if(E[u].size() == 0) return true;

		for(auto& v:E[u])
			if(dfs(v)) return true;

		return false;
	};

	if(dfs(0)) cout << "yes";
	else cout << "Yes";
}