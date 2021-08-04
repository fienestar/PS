/*
    알파벳
    https://www.acmicpc.net/problem/1987
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t R, C;
	cin >> R >> C;

	vector<vector<size_t>> board(R, vector<size_t>(C));
	for(auto& line:board)
		for(auto& v:line){
			char c;
			cin >> c;
			v = c - 'A';
		}

	size_t max_v_count = 0;
	size_t v_count = 0;
	size_t used = 0;
	function<void(size_t,size_t)> dfs = [&](size_t x, size_t y){
		used ^= 1 << board[x][y];
		++v_count;
		max_v_count = max(max_v_count, v_count);
		static int dx[] = {1,-1,0,0};
		static int dy[] = {0,0,1,-1};

		for(size_t k=0; k!=4; ++k){
			size_t mx = x + dx[k];
			size_t my = y + dy[k];

			if(mx >= R || my >= C)
				continue;

			if(used & (1 << board[mx][my]))
				continue;

			dfs(mx, my);
		}
		--v_count;
		used ^= 1 << board[x][y];
	};

	dfs(0,0);

	cout << max_v_count;
}