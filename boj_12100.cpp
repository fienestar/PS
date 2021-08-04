/*
    2048 (Easy)
    https://www.acmicpc.net/problem/12100
*/
#include <bits/stdc++.h>

using namespace std;
using cell_t = unsigned long long;
using line_t = vector<cell_t>;
using board_t = vector<line_t>;

cell_t apply_gravity(board_t& board)
{
	cell_t M = 0;
	for (size_t i = 0; i != board[0].size(); ++i) {
		size_t bl = board.size();
		for (size_t j = board.size(); j--;)
			if (board[j][i]) {
				M = max(M, board[j][i]);
				board[--bl][i] = board[j][i];
				if(bl != j)board[j][i] = 0;
			}
	}
	return M;
}

void down(board_t& board)
{
	for (size_t i = board.size(); --i;)
		for (size_t j = 0; j != board[i].size(); ++j)
			if (board[i][j] == board[i - 1][j]) {
				board[i][j] <<= 1;
				board[i - 1][j] = 0;
			}
}

board_t rotate(board_t& board)
{
	board_t new_board(board[0].size(), line_t(board.size()));
	for (size_t i = 0; i != board.size(); ++i)
		for (size_t j = 0; j != board[i].size(); ++j)
			new_board[board[i].size() - j - 1][i] = board[i][j];
	return new_board;
}

cell_t find_max(board_t board, size_t i)
{
	if (i-- == 0)
		return 0;

	cell_t M = 0;
	for (size_t k = 0; k != 4; ++k) {
		auto rotated = board = rotate(board);
		apply_gravity(rotated);
		down(rotated);
		M = max(M, apply_gravity(rotated));
		M = max(M, find_max(rotated, i));
	}

	return M;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	board_t board(N, line_t(N));
	for (auto& line : board)
		for (auto& cell : line)
			cin >> cell;

	cout << find_max(board, 5);
}
