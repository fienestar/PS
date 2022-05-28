/*
    지그재그 서기
    https://www.acmicpc.net/problem/1146
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	function<size_t(size_t, size_t)> calc = [&](size_t low, size_t high)->size_t{
		if(high == 0) return !low;

		static size_t memo[100][100];
		auto& ret = memo[low][high];

		if(ret) return ret;

		for(size_t i=0; i!=high; ++i)
			ret = (ret + calc(high-i-1,low+i)) % 1'000'000;

		return ret;
	};

	cout << (1+(N > 1)) * calc(0, N) % 1'000'000 << "\n";
}