/*
    1학년
    https://www.acmicpc.net/problem/5557
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	using ull = unsigned long long;
	
	ull begin;
	cin >> begin;

	vector<ull> v(N-2);
	for(auto& c:v)
		cin >> c;

	ull sums[2][21] = {};
	sums[0][begin] = 1;
	bool i = 1;
	for(auto& c:v){
		auto& sum = sums[i];
		auto& oth = sums[i^=1];

		for(size_t i=0; i!=c; ++i)
			sum[i] = 0;

		for(size_t i=c; i!=21; ++i)
			sum[i] = oth[i-c];

		for(size_t i=c; i!=21; ++i)
			sum[i-c] += oth[i];
	}

	auto& sum = sums[i^=1];

	size_t result;
	cin >> result;

	cout << sum[result];
}