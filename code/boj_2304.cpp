/*
    창고 다각형
    https://www.acmicpc.net/problem/2304
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<pair<size_t,size_t>> v(N*2);
	for(size_t i=0; i!=N; ++i){
		auto& [l,h] = v[i<<1];
		cin >> l >> h;

		v[i<<1|1] = {l+1, h};
	}

	sort(v.begin(), v.end());

	pair<size_t,size_t> b = {0,0};
	size_t bi = 0;
	pair<size_t,size_t> e = {1001,0};
	size_t ei = N*2;

	size_t sum = 0;

	while(bi < ei){
		while(e.second <= b.second && bi < ei){
			auto& building = v[--ei];
			if(e.second < building.second){
				sum += e.second * (e.first - building.first);
				e = building;
			}
		}
		while(b.second < e.second && bi < ei){
			auto& building = v[bi++];
			if(b.second < building.second){
				sum += b.second * (building.first - b.first);
				b = building;
			}
		}
	}

	sum += (e.first - b.first) * e.second;

	cout << sum;
}