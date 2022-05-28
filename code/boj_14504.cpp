/*
    수열과 쿼리 18
    https://www.acmicpc.net/problem/14504
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<int> A(N);
	for(auto& a:A)
		cin >> a;

	size_t box_size = sqrt(N);
	vector<vector<int>> sorted(N/box_size+1);

	auto fill_box = [&](size_t i){
		size_t fit_box_size = min(N-i*box_size, box_size);
		sorted[i].resize(fit_box_size);

		for(size_t j=0; j!=fit_box_size; ++j)
			sorted[i][j] = A[i*box_size+j];

		sort(begin(sorted[i]), end(sorted[i]));
		
	};
	for(size_t i=0; i<N/box_size+1; ++i)
		fill_box(i);

	auto update = [&](size_t i, int v){
		A[i] = v;
		fill_box(i/box_size);
	};

	auto count = [&](size_t b, size_t e, int v)->size_t{
		size_t result = 0;
		while(b % box_size && b < e) result += A[b++] > v;
		while(e % box_size && b < e) result += A[--e] > v;

		b /= box_size;
		e /= box_size;

		while(b < e){
			auto& box = sorted[b++];
			result += end(box) - upper_bound(begin(box), end(box), v);
		}

		return result;
	};

	size_t M;
	cin >> M;

	while(M--){
		size_t op, i, j; int k;
		cin >> op;

		if(op == 1){
			cin >> i >> j >> k;
			cout << count(i-1,j,k) << "\n";
		}else{
			cin >> i >> k;
			update(i-1, k);
		}
	}
}