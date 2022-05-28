/*
    하노이 탑 K
    https://www.acmicpc.net/problem/23250
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull cost(size_t n)
{
	return (1ull << n) - 1ull;
}

void hanoi(ull r, size_t n, size_t from, size_t to)
{
	if(n == 1){
		assert(r == 1);
		cout << from << " " << to;
		return;
	}

	if(r <= cost(n-1))
		return hanoi(r, n-1, from, 6-from-to);

	r -= cost(n-1);

	if(r == 1)
		cout << from << " " << to;
	else
		return hanoi(r-1, n-1, 6-from-to, to);
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	ull K;

	cin >> N >> K;

	hanoi(K, N, 1, 3);
}