/*
    문제집
    https://www.acmicpc.net/problem/1766
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	static size_t pre_count[32001] = {};
	static list<size_t> post[32001];
	while(M--){
		size_t A, B;
		cin >> A >> B;

		post[A].push_back(B);
		pre_count[B]++;
	}

	priority_queue<size_t,vector<size_t>,greater<size_t>> pq;
	for(size_t i=1; i<=N; ++i)
		if(pre_count[i] == 0)
			pq.push(i);

	while(pq.size()){
		size_t x = pq.top(); pq.pop();

		cout << x << " ";
		for(size_t y:post[x])
			if(--pre_count[y] == 0)
				pq.push(y);
	}
	
}