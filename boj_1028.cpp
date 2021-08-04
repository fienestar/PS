/*
    다이아몬드 광산
    https://www.acmicpc.net/problem/1028
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t R, C;
	cin >> R >> C;

	vector<vector<int>> board[4];
	board[0].resize(R, vector<int>(C));
	for(auto& line:board[0])
		for(auto& v:line){
			char c;
			cin >> c;
			v = c - '0';
		}

	for(size_t k=1; k!=4; ++k)
		board[k] = board[0];

	for(size_t j=0; j!=C; ++j)
		for(size_t i=0; i!=R; ++i)
			for(size_t k=0; k!=4; ++k) {
				static int dx[] = {1,-1,1,-1};
				static int dy[] = {-1,-1,1,1};

				size_t x = i;
				size_t y = j;

				if(k > 1){
					x = R - 1 - i;
					y = C - 1 - j;
				}

				size_t mx = x + dx[k];
				size_t my = y + dy[k];

				if(mx >= R || my >= C)continue;

				if(board[k][x][y])board[k][x][y] = board[k][mx][my] + 1;
			}

	size_t M = 0;
	for(size_t i=0; i!=R; ++i)
		for(size_t j=0; j!=C; ++j){
			size_t len = min(board[0][i][j], board[2][i][j]);
			while(len--){
				size_t mi = i + len * 2;

				if(mi >= R)continue;
				if(min(board[1][mi][j], board[3][mi][j]) > len){
					M = max(M, len + 1);
					break;
				}
			}
		}

	cout << M;
}