/*
    카드 정렬하기
    https://www.acmicpc.net/problem/1715
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	priority_queue<ull,vector<ull>,greater<ull>> pq;
	while(N--){
		ull s;
		cin >> s;
		pq.push(s);
	}

	ull sum = 0;
	while(pq.size() != 1){
		ull a = pq.top(); pq.pop();
		ull b = pq.top(); pq.pop();

		sum += a+b;
		pq.push(a+b);
	}

	cout << sum;
}