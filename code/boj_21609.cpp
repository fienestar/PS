/*
    상어 중학교
    https://www.acmicpc.net/problem/21609
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(N));
	for (auto& line : board)
		for (auto& color : line)
			cin >> color;

	vector<vector<uint8_t>> zeros(N, vector<uint8_t>(N));
	auto visited = zeros;
	auto foreach_block = [&](size_t i, size_t j, function<void(size_t, size_t)> cb) {
		if (board[i][j] <= 0 || visited[i][j] || board[i][j] == M+1)
			return;

		queue<pair<size_t, size_t>> q;

		visited[i][j] = true;
		q.emplace(i, j);

		size_t color = board[i][j];
		auto rainbow = zeros;
		while (!q.empty()) {
			auto [x, y] = q.front();
			q.pop();
			cb(x, y);

			for (auto [dx, dy] : { pair{1,0},{-1,0},{0,1},{0,-1} }) {
				auto [mx, my] = pair{ x + dx, y + dy };

				if (mx >= N || my >= N) continue;
				if (board[mx][my] && board[mx][my] != color) continue;
				if (visited[mx][my] || rainbow[mx][my]) continue;

				if (board[mx][my] == 0)
					rainbow[mx][my] = true;
				else
					visited[mx][my] = true;

				q.emplace(mx, my);
			}
		}
	};

	size_t score = 0;
	auto click = [&]() {
		tuple<size_t, size_t, pair<size_t, size_t>> max_block = { 0,0,{0,0} };
		for (size_t i = 0; i != N; ++i)
			for (size_t j = 0; j != N; ++j) {
				size_t count = 0;
				pair<size_t, size_t> base = { i,j };
				size_t rainbow_count = 0;
				foreach_block(i, j, [&](size_t x, size_t y) {
					++count;
					if (board[x][y] != 0) base = min(base, { x,y });
					else ++rainbow_count;
				});

				max_block = max(max_block, tuple{ count, rainbow_count, base });
			}

		auto [count, rainbow_count,  pos] = max_block;
		auto [i, j] = pos;

		if (count < 2)
			return false;

		score += count * count;

		visited = zeros;
		foreach_block(i, j, [&](size_t x, size_t y) {
			board[x][y] = M+1;
		});
		visited = zeros;

		// cout << "click " << i << ", " << j << " and get " << count * count << "\n";

		return true;
	};

	auto rotate = [&]() {
		auto origin = board;
		for (size_t i = 0; i != N; ++i)
			for (size_t j = 0; j != N; ++j)
				board[i][j] = origin[j][N - i - 1];
	};

	auto gravity = [&]() {
		for (size_t j = 0; j != N; ++j) {
			size_t base = N-1;
			for (size_t i = N; i--; ) {
				if (board[i][j] == -1)
					base = i;
				if (board[i][j] != M+1)
					swap(board[i][j], board[base--][j]);
			}
		}
	};

	auto print = [&]() {
		for (auto& line : board) {
			for (auto& color : line)
				if (color == -1) cout << "- ";
				else if (color == M + 1) cout << "  ";
				else cout << color << " ";
			cout << "\n";
		}
		cout << "===========\n";
	};

	while (click()) {
		// print();
		gravity();
		rotate();
		gravity();
	}

	cout << score;
}