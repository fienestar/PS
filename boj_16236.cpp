/*
    아기 상어
    https://www.acmicpc.net/problem/16236
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<vector<size_t>> space(N, vector<size_t>(N));
	size_t i,j,sz=2;
	for(auto& line:space)
		for(auto& element:line){
			cin >> element;
			if(element == 9){
				i = &line - &space[0];
				j = &element - &line[0];
			}
		}

	auto find = [&](size_t i, size_t j, size_t sz)->tuple<size_t,size_t,size_t>{
		queue<pair<size_t,size_t>> q;
		bool visited[20][20] = {};

		size_t found_x = -1, found_y = -1;
		q.emplace(i,j);
		q.emplace(-1,-1);
		space[i][j] = 0;
		visited[i][j] = true;

		size_t dist = 0;

		while(true){
			auto[x,y] = q.front();
			q.pop();
			if(x == -1 && y == -1){
				++dist;

				if(found_x != -1)
					return {found_x,found_y,dist};

				if(q.size() == 0)
					return {-1,-1,0};

				q.emplace(-1,-1);
				continue;
			}

			static int dx[] = {-1,0,0,1};
			static int dy[] = {0,-1,1,0};
			for(size_t k=0; k!=4; ++k){
				size_t mx = x + dx[k];
				size_t my = y + dy[k];

				if(mx >= N || my >= N)continue;
				if(visited[mx][my])continue;
				if(space[mx][my] > sz)continue;

				if(space[mx][my] && space[mx][my] < sz && (mx < found_x || (mx == found_x && my < found_y))){
						found_x = mx;
						found_y = my;
				}

				visited[mx][my] = true;
				q.emplace(mx,my);
			}
		}
	};

	size_t time = 0;
	size_t total_time = 0;
	size_t eat_count = 0;
	do{
		if(eat_count == sz){
			++sz;
			eat_count = 0;
		}

		tie(i,j,time) = find(i,j,sz);
		eat_count += 1;
		total_time += time;
	}while(time);

	cout << total_time;
}