/*
    가장 긴 증가하는 부분 수열 5
    https://www.acmicpc.net/problem/14003
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<int> A(N);
	for (auto& c : A)
		cin >> c;

	vector<int> sub(N);
	vector<size_t> idx(N);
	size_t len = 0;

	for (size_t i = 0; i != N; ++i) {
		size_t j = lower_bound(sub.begin(), sub.begin() + len, A[i]) - sub.begin();
		len = max(len, j + 1);
		sub[j] = A[i];
		idx[i] = j;
	}

	cout << len << "\n";

	size_t j = len - 1;
	for (size_t i = N; i--;)
		if (idx[i] == j) {
			sub[j] = A[i];
			j--;
		}

	for (size_t i = 0; i != len; ++i)
		cout << sub[i] << " ";
}