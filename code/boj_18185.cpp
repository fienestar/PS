/*
    라면 사기 (Small)
    https://www.acmicpc.net/problem/18185
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> A(N);
	for(auto& a:A)
		cin >> a;

	A.resize(N+2, 0);

	size_t cost = 0;
	for(size_t i=0; i!=N; ++i){
		if(A[i+1] > A[i+2]){
			size_t m = min(A[i],A[i+1]-A[i+2]);
			A[i] -= m;
			A[i+1] -= m;
			cost += m*5;
		}

		for(size_t j=3; j--; ) {
			size_t m = A[i];
			for(size_t k=1; k<=j; ++k)
				m = min(m, A[i+k]);
			for(size_t k=0; k<=j; ++k)
				A[i+k] -= m;

			cost += m*(3+2*j);
		}
	}

	cout << cost;
}