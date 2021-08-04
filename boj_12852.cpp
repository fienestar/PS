/*
    1로 만들기 2
    https://www.acmicpc.net/problem/12852
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	static size_t count[1'000'001] = {};
	static size_t next[1'000'001] = {};
	count[1] = 1;
	next[1] = 0;

	auto update = [&](size_t i, size_t j){
		if(i > 1'000'000)return;
		if(count[i] && count[i] <= count[j]+1)return;

		count[i] = count[j] + 1;
		next[i] = j;
	};

	for(size_t i=1; i!=N; ++i){
		update(i+1,i);
		update(i*2,i);
		update(i*3,i);
	}

	cout << count[N] - 1 << "\n";

	cout << N << " ";
	while(next[N])
		cout << (N = next[N]) << " ";
}