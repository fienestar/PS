/*
    Sort 마스터 배지훈의 후계자
    https://www.acmicpc.net/problem/20551
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N, M;
	cin >> N >> M;

	size_t sz = 1;
	while(sz < N)sz <<= 1;
	vector<int> seg(sz * 2, 2'000'000'000);

	for(size_t i=0; i!=N; ++i)
		cin >> seg[sz+i];

	sort(seg.begin()+sz, seg.end());

	for(size_t i=sz; i--;)
		seg[i] = max(seg[i<<1], seg[i<<1|1]);

	while(M--){
		int D;
		cin >> D;

		size_t i=1;
		while(i < sz){
			size_t l = i << 1;
			size_t r = l|1;

			if(seg[l] >= D)
				i = l;
			else
				i = r;	
		}

		if(seg[i] != D)
			cout << -1 << "\n";
		else
			cout << i - sz << "\n";
	}
}