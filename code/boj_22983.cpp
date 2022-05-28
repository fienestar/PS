/*
    조각 체스판
    https://www.acmicpc.net/problem/22983
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<vector<uint8_t>> board(N, vector<uint8_t>(M));

	for(auto& line:board)
		for(auto& d:line){
			char c;
			cin >> c;
			d = c == 'B';
		}

	size_t sum = 0;
	vector<vector<size_t>> dp(N, vector<size_t>(M));
	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=M; ++j){
			auto& k = dp[i][j] = 1;

			if(i && j && board[i-1][j] != board[i-1][j-1] && board[i][j-1] != board[i-1][j-1] && board[i][j] == board[i-1][j-1])
				k = min({ dp[i-1][j-1], dp[i-1][j], dp[i][j-1] }) + 1;

			sum += k;
		}

	cout << sum;
}