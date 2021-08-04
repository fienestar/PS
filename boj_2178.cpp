/*
    미로 탐색
    https://www.acmicpc.net/problem/2178
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N, M;
	cin >> N >> M;

	vector<vector<int>> v(N, vector<int>(M));
	for(auto& line:v)
		for(auto& c:line){
			char ch;
			cin >> ch;
			c = ch - '0';
		}

	queue<pair<size_t, size_t>> q;
	size_t time = 0;

	q.emplace(0,0);
	q.emplace(-1,-1);
	while(!q.empty()){
		auto[i,j] = q.front();
		q.pop();

		if(i == -1){
			++time;
			q.emplace(-1,-1);
			continue;
		}

		static int di[] = {1,-1,0,0};
		static int dj[] = {0,0,1,-1};
		for(size_t k=0; k!=4; ++k){
			size_t mi = i + di[k];
			size_t mj = j + dj[k];

			if(mi == N-1 && mj == M-1){
				cout << time + 2;
				return 0;
			}

			if(mi >= N || mj >= M)
				continue;

			if(v[mi][mj] == 0)
				continue;

			v[mi][mj] = 0;
			q.emplace(mi, mj);
		}
	}
}