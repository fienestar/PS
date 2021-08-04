/*
    도로 네트워크
    https://www.acmicpc.net/problem/3176
*/
#include <bits/stdc++.h>

using namespace std;

struct max_min_t
{
	size_t M;
	size_t m;

	max_min_t updated(max_min_t oth)
	{
		return {
			max(M, oth.M),
			min(m, oth.m)
		};
	}

	void update(max_min_t oth)
	{
		*this = this->updated(oth);
	}
};

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

	vector<vector<size_t>> parent(N, vector<size_t>(18));
	vector<vector<max_min_t>> parent_max_min(N, vector<max_min_t>(18));
	vector<size_t> dept(N);
	size_t dept_i = 1;
	function<void(size_t)> mark_dept = [&](size_t v){
		dept[v] = dept_i;

		++dept_i;

		for(auto c:E[v])
			if(!dept[c.first]){
				parent[c.first][0] = v;
				parent_max_min[c.first][0] = {c.second, c.second};
				mark_dept(c.first);
			}

		--dept_i;
	};

	mark_dept(0);

	for(size_t i=1; i!=18; ++i)
		for(size_t j=0; j!=N; ++j){
			parent[j][i] = parent[parent[j][i-1]][i-1];
			parent_max_min[j][i] = parent_max_min[j][i-1].updated(parent_max_min[parent[j][i-1]][i-1]);
		}

	size_t M;
	cin >> M;

	while(M--){
		size_t a, b;
		cin >> a >> b;
		--a; --b;

		if(dept[a] < dept[b])swap(a,b);
		size_t diff = dept[a] - dept[b];

		max_min_t result = {0, size_t(-1)};
		for(size_t i=0; diff; ++i){
			if(diff&1){
				result.update(parent_max_min[a][i]);
				a = parent[a][i];
			}
			diff /= 2;
		}

		if(a != b){
			for(size_t i=18; i--;)
				if(parent[a][i] != parent[b][i]){
					result.update(parent_max_min[a][i]);
					result.update(parent_max_min[b][i]);
					a = parent[a][i];
					b = parent[b][i];
				}

			result.update(parent_max_min[a][0]);
			result.update(parent_max_min[b][0]);
		}

		cout << result.m << " " << result.M << "\n";
	}
}