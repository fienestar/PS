/*
    좋다
    https://www.acmicpc.net/problem/1253
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<int> A(N);
	for(auto& a:A)
		cin >> a;

	sort(A.begin(), A.end());

	using pis = pair<int,ull>;
	vector<pis> F;
	F.reserve(N);

	pis tmp = {0,0};
	pis *last = &tmp;
	size_t zero_cnt = 0;
	for(auto& a:A)
		if(a == 0)
			++zero_cnt;
		else if(a == last->first)
			++last->second;
		else{
			F.emplace_back(a,1);
			last =  &F[F.size()-1];
		}

	vector<int> pair_sum;
	pair_sum.reserve(N*N);

	for(auto& a:F)
		for(auto& b:F)
			if(a.first != b.first || a.second >= 2)
				pair_sum.push_back(a.first + b.first);

	sort(pair_sum.begin(), pair_sum.end());

	auto has = [&pair_sum](int n){
		return binary_search(pair_sum.begin(), pair_sum.end(), n);
	};

	size_t cnt = 0;
	for(auto& a:F)
		if(has(a.first)){
			cnt += a.second;
			a.second = 0;
		}

	if(zero_cnt){
		for(auto& a:F)
			if(a.second >= 2){
				cnt += a.second;
				a.second = 0;
			}

		if(zero_cnt >= 3 || has(0))
			cnt += zero_cnt;
	}

	cout << cnt;
}