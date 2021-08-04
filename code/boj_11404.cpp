/*
    플로이드
    https://www.acmicpc.net/problem/11404
*/
#include <bits/stdc++.h>

using namespace std;

#define infinity 0x3F3F3F3F

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N, M;
	cin >> N >> M;

	vector<vector<int>> dist(N, vector<int>(N, infinity));
	while(M--){
		size_t a, b;
		int c;
		cin >> a >> b >> c;

		dist[a-1][b-1] = min(dist[a-1][b-1], c);
	}

	for(size_t i=0; i!=N; ++i)
		dist[i][i] = 0;

	for(size_t k=0; k!=N; ++k)
		for(size_t i=0; i!=N; ++i)
			for(size_t j=0; j!=N; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(auto& line:dist){
		for(auto& e:line)
			if(e == infinity) cout << 0 << " "; else cout << e << " ";
		cout << "\n";
	}
}