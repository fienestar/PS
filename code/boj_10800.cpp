/*
    컬러볼
    https://www.acmicpc.net/problem/10800
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<tuple<ull, size_t, size_t>> C(N);
	for(size_t i=0; i!=N; ++i){
		auto& [size, color, index] = C[i];
		cin >> color >> size;
		--color;
		index = i;
	}

	sort(C.begin(), C.end());

	vector<ull> color_sz_sum(N);
	ull sz_sum = 0;
	vector<ull> ans(N);
	for(size_t i=0; i!=N;){
		size_t g_size = get<0>(C[i]);
		size_t j;

		for(j=i; j!=N; ++j){
			auto& [size, color, index] = C[j];
			if(g_size != size)
				break;

			ans[index] = sz_sum - color_sz_sum[color];
		}

		for(j=i; j!=N; ++j){
			auto& [size, color, index] = C[j];
			if(g_size != size)
				break;

			sz_sum += size;
			color_sz_sum[color] += size;
		}

		i = j;
	}

	for(auto& c:ans)
		cout << c << "\n";
}