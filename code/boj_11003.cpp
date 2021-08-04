/*
    최솟값 찾기
    https://www.acmicpc.net/problem/11003
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	using ll = long long;
	size_t N, L;
	cin >> N >> L;

	vector<ll> v(N);
	for(auto& c:v)
		cin >> c;

	priority_queue<ll> pq;
	priority_queue<ll> deleted_pq;

	for(size_t i=0; i!=L; ++i){
		pq.push(-v[i]);
		cout << -pq.top() << " ";
	}

	for(size_t i=L; i!=N; ++i){
		deleted_pq.push(-v[i-L]);
		pq.push(-v[i]);

		while(deleted_pq.size() && pq.top() == deleted_pq.top()){
			pq.pop();
			deleted_pq.pop();
		}

		cout << -pq.top() << " ";
	}
}