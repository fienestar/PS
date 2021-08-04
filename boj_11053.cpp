/*
    가장 긴 증가하는 부분 수열
    https://www.acmicpc.net/problem/11053
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<int> sub(N);
	size_t len = 0;

	for (size_t i=0; i!=N; ++i) {
		int a;
		cin >> a;

		size_t j = lower_bound(sub.begin(), sub.begin() + len, a) - sub.begin();
		len = max(len, j + 1);
		sub[j] = a;
	}

	cout << len;
}