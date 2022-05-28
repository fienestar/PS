/*
    최대 직사각형
    https://www.acmicpc.net/problem/11873
*/
#include <bits/stdc++.h>

using namespace std;

size_t max_score = 0;

// [begin, end)
void dnc(size_t* A, size_t begin, size_t end)
{
	if(begin >= end)
		return;

	size_t mid = (begin + end)/2;

	dnc(A, begin, mid);
	dnc(A, mid + 1, end);

	// -> [begin, end]
	--end;

	size_t m = A[mid];

	size_t b = mid;
	size_t e = mid;

	while(true){
		while(b != begin && m <= A[b-1])--b;
		while(e != end   && m <= A[e+1])++e;

		max_score = max(max_score, m * (e-b+1));

		size_t target;

		if(b != begin && (e == end || A[e+1] <= A[b-1]))
			target = A[--b];
		else if(e != end   && (b == begin || A[e+1] >= A[b-1]))
			target = A[++e];
		else
			break;

		m = min(m, target);
	}
}

void solve(size_t N, size_t M)
{
	static size_t AL[1000][1000];
	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=M; ++j)
			cin >> AL[i][j];

	for(size_t i=1; i!=N; ++i)
		for(size_t j=0; j!=M; ++j)
			if(AL[i][j])
				AL[i][j] += AL[i-1][j];

	max_score = 0;
	for(size_t i=0; i!=N; ++i)
		dnc(AL[i], 0, M);

	cout << max_score << "\n";
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	while(cin >> N >> M)
		if(N)solve(N,M);
}
