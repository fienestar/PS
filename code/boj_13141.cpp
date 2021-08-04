/*
    Ignition
    https://www.acmicpc.net/problem/13141
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	vector<vector<size_t>> C(N, vector<size_t>(N, -1));
	vector<vector<size_t>> MC(N, vector<size_t>(N, 0));

	while(M--){
		size_t a,b,c;

		cin >> a >> b >> c;
		--a; --b;

		C[a][b] = min(C[a][b], c);
		C[b][a] = min(C[b][a], c);
		MC[a][b] = max(MC[a][b], c);
		MC[b][a] = max(MC[b][a], c);
	}

	for(size_t i=0; i!=N; ++i)
		C[i][i] = 0;

	for(size_t k=0; k!=N; ++k)
		for(size_t i=0; i!=N; ++i)
			if(C[i][k] != -1)
				for(size_t j=0; j!=N; ++j)
					if(C[k][j] != -1)
						C[i][j] = min(C[i][j], C[i][k] + C[k][j]);

	size_t min_cost = -1;
	for(size_t i=0; i!=N; ++i){
		size_t cost = 0;
		for(size_t j=0; j!=N; ++j){
			cost = max(cost, C[i][j]*10);

			for(size_t k=0; k!=N; ++k)
				if(MC[j][k] != 0){
					size_t L = MC[j][k];
					size_t M = C[i][j];
					size_t m = C[i][k];

					if(m > M)swap(m, M);
					if(L < M - m)continue;

					cost = max(cost, M*10 + (L - (M - m)) * 5);
				}
		}
		min_cost = min(min_cost, cost);
	}

	cout << min_cost/10 << "." << min_cost%10;
}