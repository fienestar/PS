/*
    역사
    https://www.acmicpc.net/problem/1613
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<vector<char>> gt(N+1, vector<char>(N+1));

	size_t K;
	cin >> K;
	while(K--){
		size_t a, b;
		cin >> a >> b;
		gt[a][b] = true;
	}

	for(size_t k=1; k<=N; ++k)
		for(size_t i=1; i<=N; ++i)
			if(gt[i][k])
				for(size_t j=1; j<=N; ++j)
					gt[i][j] |= gt[k][j];

	size_t S;
	cin >> S;
	while(S--){
		size_t a, b;
		cin >> a >> b;

		if(gt[a][b])
			cout << "-1\n";
		else if(gt[b][a])
			cout << "1\n";
		else
			cout << "0\n";
	}
}