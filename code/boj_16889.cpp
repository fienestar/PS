/*
    중복 없는 님 게임
    https://www.acmicpc.net/problem/16889
*/
#include <bits/stdc++.h>

using namespace std;

size_t grundy(size_t p)
{
	return (size_t)lower_bound((char*)0, (char*)1'000'000, false, [&](char& pn, bool) {
		size_t n = (size_t)&pn;
		return n * (n + 1) / 2 < p+1;
	})-1;
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t p;
	cin >> p;

	size_t g = 0;
	while (cin >> p)
		g ^= grundy(p);

	if (g)
		cout << "koosaga";
	else
		cout << "cubelover";
}