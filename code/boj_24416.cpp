/*
    알고리즘 수업 - 피보나치 수 1
    https://www.acmicpc.net/problem/24416
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<size_t> fibo(N+1);
	fibo[1] = fibo[2] = 1;
	for(size_t i=3; i<=N; ++i)
		fibo[i] = fibo[i-1] + fibo[i-2];

	cout << fibo[N] << " " << max(N,(size_t)2)-2;
}