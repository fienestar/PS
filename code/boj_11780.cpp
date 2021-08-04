/*
    플로이드 2
    https://www.acmicpc.net/problem/11780
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
	vector<vector<size_t>> next(N, vector<size_t>(N, infinity));
	while(M--){
		size_t a, b;
		int c;
		cin >> a >> b >> c;
		--a; --b;

		if(c < dist[a][b]){
			dist[a][b] = c;
			next[a][b] = b;
		}
	}

	for(size_t i=0; i!=N; ++i){
		dist[i][i] = 0;
		next[i][i] = i;
	}

	for(size_t k=0; k!=N; ++k)
		for(size_t i=0; i!=N; ++i)
			for(size_t j=0; j!=N; ++j)
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					next[i][j] = next[i][k];
				}

	for(auto& line:dist){
		for(auto& e:line)
			if(e == infinity) cout << 0 << " "; else cout << e << " ";
		cout << "\n";
	}

	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=N; ++j)
			if(dist[i][j] == infinity || i == j)
				cout << 0 << "\n";
			else{
				list<size_t> path;

				size_t b = i;
				path.push_back(b+1);
				do{
					b = next[b][j];
					path.push_back(b+1);
				}while(b != j);

				cout << path.size() << " ";
				for(auto& v:path)
					cout << v << " ";
				cout << "\n";
			}
}