/*
    군대탈출하기
    https://www.acmicpc.net/problem/14948
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t n,m;
	cin >> n >> m;

	vector<vector<size_t>> min_level(n, vector<size_t>(m));
	for(auto& c:min_level)
		for(auto& m:c)
			cin >> m;
	

	vector<vector<bool>> updatings[2];
	for(auto& u:updatings)u.resize(n, vector<bool>(m, false));

	vector<vector<size_t>> updated_min_levels[2];
	for(auto& u:updated_min_levels)u.resize(n, vector<size_t>(m,-1));

	queue<pair<size_t,pair<size_t,size_t>>> q;
	q.emplace(false,make_pair(0,0));

	auto update = [&](size_t& obj, size_t src){
		if(obj > src){
			obj = src;
			return true;
		}

		return false;
	};

	update(updated_min_levels[0][0][0],min_level[0][0]);

	while(not q.empty()){
		auto[used, pos] = q.front();
		auto[x,y] = pos;
		q.pop();
		updatings[used][x][y] = false;

		static int dx[] = {1,-1,0,0};
		static int dy[] = {0,0,1,-1};

		for(size_t f=0; f+used != 2; ++f)
			for(size_t k=0; k!=4; ++k){
				size_t mx = x + dx[k] * (f + 1);
				size_t my = y + dy[k] * (f + 1);

				if(mx >= n || my >= m)
					continue;

				size_t needed = max(min_level[mx][my], updated_min_levels[used][x][y]);

				if(not update(updated_min_levels[f+used][mx][my], needed))
					continue;

				if(not updatings[f+used][mx][my]){
					q.emplace(f+used, make_pair(mx, my));
					updatings[f+used][mx][my] = true;
				}
			}
	}

	cout << min(updated_min_levels[0][n-1][m-1], updated_min_levels[1][n-1][m-1]);
}