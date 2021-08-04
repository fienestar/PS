/*
    보석
    https://www.acmicpc.net/problem/2492
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	using l = uint32_t;

	l N, M, T, K;
	cin >> N >> M >> T >> K;

	vector<l> xs(T+1);
	vector<l> ys(T+1);
	vector<pair<l,l>> poss(T);
	for(size_t i=0; i!=T; ++i){
		cin >> xs[i] >> ys[i];
		poss[i] = {xs[i], ys[i]};
	}

	xs[T] = N - K;
	ys[T] = M - K;

	l ans_x, ans_y;
	l ans = 0;
	for(auto x:xs)
		for(auto y:ys){
			if(x + K > N || y + K > M)
				continue;

			l c = 0;
			for(auto& pos:poss)
				c += (pos.first - x <= K && pos.second - y <= K);
			if(c > ans){
				ans = c;
				ans_x = x;
				ans_y = y + K;
			}
		}

	cout << ans_x << " " << ans_y << "\n";
	cout << ans;
}