/*
    알고리즘 수업 - 피보나치 수 2
    https://www.acmicpc.net/problem/24417
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	size_t fibo[3];
	fibo[1] = fibo[2] = 1;
	for(size_t i=3; i<=N; i+=3){
		fibo[i%3] = (fibo[(i+2)%3] + fibo[(i+1)%3]);
		fibo[(i+1)%3] = (fibo[(i+2)%3] + fibo[i%3]);
		fibo[(i+2)%3] = (fibo[(i+1)%3] + fibo[i%3]) % 1'000'000'007;
	}

	cout << fibo[N%3] % 1'000'000'007 << " " << (max(N,(size_t)2)-2) % 1'000'000'007;
}