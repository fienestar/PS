/*
    히스토그램
    https://www.acmicpc.net/problem/1725
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull A[100000];
size_t N;
ull max_score = 0;

// [begin, end)
void dnc(size_t begin, size_t end)
{
	if(begin >= end)
		return;

	size_t mid = (begin + end)/2;

	dnc(begin, mid);
	dnc(mid + 1, end);

	// -> [begin, end]
	--end;

	ull m = A[mid];

	size_t b = mid;
	size_t e = mid;

	while(true){
		while(b != begin && m <= A[b-1])--b;
		while(e != end   && m <= A[e+1])++e;

		max_score = max(max_score, m * (e-b+1));

		ull target;

		if     (b != begin && (e == end   || A[e+1] <= A[b-1]))
			target = A[--b];
		else if(e != end   && (b == begin || A[e+1] >= A[b-1]))
			target = A[++e];
		else
			break;

		m = min(m, target);
	}
}

int main()
{
	cin >> N;

	for(size_t i=0; i!=N; ++i)
		cin >> A[i];

	max_score = 0;
	dnc(0,N);

	cout << max_score << "\n";
}
