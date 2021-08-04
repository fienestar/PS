/*
    오아시스 재결합
    https://www.acmicpc.net/problem/3015
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	stack<pair<int, size_t>> s;
	size_t count = 0;

	while(N--){
		int n;
		cin >> n;

		while(not s.empty() and s.top().first < n){
			count += s.top().second;
			s.pop();
		}

		if(not s.empty() and s.top().first == n)
			count += s.top().second++;
		else
			s.emplace(n, 1);

		if(s.size() >= 2)
			++count;
	}

	cout << count;
}