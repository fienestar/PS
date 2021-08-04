/*
    벽 부수고 이동하기 4
    https://www.acmicpc.net/problem/16946
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, M;
	cin >> N >> M;

	vector<vector<int>> board(N,vector<int>(M));

	for(auto& line:board)
		for(auto& dot:line){
			char c;
			cin >> c;
			dot = c - '0';
		}

	static size_t region_size[1'000'003] = {};
	size_t region_id_i = 2;

	static int dx[] = {1,-1,0,0};
	static int dy[] = {0,0,1,-1};

	auto bfs = [&](size_t x, size_t y) {
		if(board[x][y])return;

		size_t region_id = region_id_i++;

		queue<pair<size_t,size_t>> q;
		q.emplace(x,y);
		board[x][y] = region_id;
		++region_size[region_id];

		while(not q.empty()){
			auto[x,y] = q.front();
			q.pop();

			for(size_t k=0; k!=4; ++k){
				size_t mx = x + dx[k];
				size_t my = y + dy[k];

				if(mx >= N || my >= M)continue;
				if(board[mx][my])continue;

				q.emplace(mx,my);
				board[mx][my] = region_id;
				++region_size[region_id];
			}
		}
	};

	auto count = [&](size_t x, size_t y) {
		list<size_t> visited;
		size_t sum = 0;

		for(size_t k=0; k!=4; ++k){
			size_t mx = x + dx[k];
			size_t my = y + dy[k];

			if(mx >= N || my >= M)continue;
			if(find(visited.begin(), visited.end(), board[mx][my]) != visited.end())continue;

			sum += region_size[board[mx][my]];
			visited.push_back(board[mx][my]);
		}

		return sum + 1;
	};

	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=M; ++j)
			bfs(i,j);

	for(size_t i=0; i!=N; ++i){
		for(size_t j=0; j!=M; ++j)
			if(board[i][j] == 1)
				cout << count(i,j) % 10;
			else
				cout << 0;
		cout << "\n";
	}
}