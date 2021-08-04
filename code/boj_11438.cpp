/*
    LCA 2
    https://www.acmicpc.net/problem/11438
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<list<size_t>> E(N);
	for(size_t i=1; i!=N; ++i){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		E[a].push_back(b);
		E[b].push_back(a);
	}

	vector<vector<size_t>> parent(N, vector<size_t>(18));
	vector<size_t> dept(N);
	size_t dept_i = 1;
	function<void(size_t)> mark_dept = [&](size_t v){
		dept[v] = dept_i;

		++dept_i;

		for(auto c:E[v])
			if(!dept[c]){
				parent[c][0] = v;
				mark_dept(c);
			}

		--dept_i;
	};

	mark_dept(0);

	for(size_t i=1; i!=18; ++i)
		for(size_t j=0; j!=N; ++j)
			parent[j][i] = parent[parent[j][i-1]][i-1];

	size_t M;
	cin >> M;

	while(M--){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		if(dept[a] < dept[b])swap(a,b);
		size_t diff = dept[a] - dept[b];

		for(size_t i=0; diff; ++i){
			if(diff&1) a = parent[a][i];
			diff /= 2;
		}

		if(a != b){
			for(size_t i=18; i--;)
				if(parent[a][i] != parent[b][i]){
					a = parent[a][i];
					b = parent[b][i];
				}

			a = parent[a][0];
		}

		cout << a+1 << "\n";
	}
}