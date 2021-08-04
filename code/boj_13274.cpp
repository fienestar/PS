/*
    수열
    https://www.acmicpc.net/problem/13274
*/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, K;
	cin >> N >> K;

	vector<ll> S[2];
	S[0].resize(N);
	S[1].resize(N);

	for(auto& a:S[0])
		cin >> a;

	sort(S[0].begin(), S[0].end());

	bool k=0;
	while(K--){
		auto& A = S[k];
		auto& B = S[k^=1];
		size_t L, R;
		ll X;
		cin >> L >> R >> X;
        
        assert(R != 2 || L != 99999);

		for(size_t i=--L; i!=R; ++i)
			A[i] += X;

		pair<size_t, size_t> ranges[] = {
			{0, L},
			{L, R},
			{R, N}
		};

		for(size_t i=0; i!=N; ++i){
			size_t m = -1;
			for(size_t j=0; j!=3; ++j)
				if(ranges[j].first != ranges[j].second &&
					( m == -1 || A[ranges[j].first] < A[ranges[m].first] ))
					m = j;

			B[i] = A[ranges[m].first++];
		}
	}

	for(auto& a:S[k])
		cout << a << " ";
}