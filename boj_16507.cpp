/*
    어두운 건 무서워
    https://www.acmicpc.net/problem/16507
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N,M,Q;
	cin >> N >> M >> Q;

	vector<vector<ull>> m(N+1,vector<ull>(M+1,0));

	for(size_t i=1; i<=N; ++i)
		for(size_t j=1; j<=M; ++j){
			cin >> m[i][j];
			m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];
		}

	while(Q--){
		size_t r1,c1,r2,c2;
		cin >> r1 >> c1 >> r2 >> c2;
		cout << (m[r2][c2] - m[r1-1][c2] - m[r2][c1-1] + m[r1-1][c1-1]) / ((r2-r1+1)*(c2-c1+1)) << "\n";
	}
}