/*
    루트 님 게임
    https://www.acmicpc.net/problem/16887
*/
#include <bits/stdc++.h>

using namespace std;

pair<size_t, size_t> grundy(size_t x);

// for x > 1
size_t calc_grundy(size_t x)
{
	size_t y = 0;
	while (y * y * y * y < x) ++y;
	bool has[100] = {};

	while (y * y <= x) {
		auto [n, count] = grundy(y);
		has[n] = true;
		y += count;
	}

	size_t result = 0;
	while (has[result]) ++result;

	return result;
}

pair<size_t, size_t> prep(size_t x)
{
	static vector<pair<size_t, size_t>> v = { {0,4},{1,12},{2,66},{0,6642},{3,43902},{1,9949375} };
	for (auto& [n, count] : v) {
		if (x < count) return { n, count - x };
		x -= count;
	}
}

pair<size_t,size_t> grundy(size_t x)
{
	if (x <= 10'000'000) return prep(x);
	else return { calc_grundy(x), 1 };
}

void init()
{
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	size_t g = 0;
	size_t a;
	while (cin >> a)
		g ^= grundy(a).first;

	if (g)
		cout << "koosaga";
	else
		cout << "cubelover";
}