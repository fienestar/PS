/*
    소트
    https://www.acmicpc.net/problem/1083
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> v(N);
	for(auto& c:v) cin >> c;

	size_t S;
	cin >> S;

	size_t k = 0;
	vector<size_t> dist(N);
	for(size_t k=0; k!=N; ++k){
		for(size_t j=0; j!=N; ++j)dist[j] = j;
		sort(begin(dist),end(dist),[&](size_t a, size_t b){
			return v[a] > v[b];
		});

		for(size_t i=0; i!=N; ++i)
			if(dist[i] > k && S >= dist[i]-k && v[k] < v[dist[i]]){
				for(size_t j=dist[i]; j>k; --j)
					swap(v[j], v[j-1]);
				S -= dist[i]-k;
				break;
			}
	}

	for(auto& c:v) cout << c << " ";
}