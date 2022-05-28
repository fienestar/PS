/*
    회전 초밥
    https://www.acmicpc.net/problem/15961
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, d, k, c;
	cin >> N >> d >> k >> c;


	vector<size_t> foods(N);
	for(auto& food:foods)
		cin >> food;

	size_t count = 0;
	size_t max_count = 0;
	vector<size_t> selected(d+1);
	auto add = [&](size_t food){
		if(!selected[food])
			max_count = max(max_count, ++count);
		++selected[food];
	};

	auto sub = [&](size_t food){
		--selected[food];
		if(!selected[food])
			--count;
	};

	for(size_t i=0; i!=k; ++i)
		add(foods[i]);
	add(c);

	for(size_t i=0; i!=N; ++i){
		sub(foods[i]);
		add(foods[(i+k)%N]);
	}

	cout << max_count;
}