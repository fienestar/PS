/*
    부분배열 고르기
    https://www.acmicpc.net/problem/2104
*/
#include <bits/stdc++.h>

using namespace std;

size_t A[100000];
size_t N;
size_t max_score = 0;

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

	size_t m = A[mid];
	size_t sum = A[mid];

	size_t b = mid;
	size_t e = mid;

	while(true){
		while(b != begin && m <= A[b-1])sum += A[--b];
		while(e != end   && m <= A[e+1])sum += A[++e];

		max_score = max(max_score, sum * m);

		size_t target;

		if     (b != begin && (e == end   || A[e+1] <= A[b-1]))
			target = A[--b];
		else if(e != end   && (b == begin || A[e+1] >= A[b-1]))
			target = A[++e];
		else
			break;

		m = min(m, target);
		sum += target;
	}
}

int main()
{
	cin >> N;

	for(size_t i=0; i!=N; ++i)
		cin >> A[i];

	dnc(0,N);

	cout << max_score;
}