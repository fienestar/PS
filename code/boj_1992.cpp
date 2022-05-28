/*
    쿼드트리
    https://www.acmicpc.net/problem/1992
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<vector<uint8_t>> board(N, vector<uint8_t>(N));
	for(auto& line:board)
		for(auto& d:line){
			char c;
			cin >> c;
			d = c - '0';
		}

	function<void(size_t,size_t,size_t)> div = [&](size_t x, size_t y, size_t n){
		bool is_same = true;
		for(size_t i=x; i!=x+n; ++i)
			for(size_t j=y; j!=y+n; ++j)
				if(board[i][j] != board[x][y]){
					is_same = false;
					break;
				}

		if(is_same){
			cout << +board[x][y];
			return;
		}

		cout << "(";
		n >>= 1;
		div(x,y,n);
		div(x,y+n,n);
		div(x+n,y,n);
		div(x+n,y+n,n);
		cout << ")";
	};

	div(0,0,N);
}