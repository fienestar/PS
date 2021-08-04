/*
    계단 수
    https://www.acmicpc.net/problem/1562
*/
#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
enum{ MOD = 1'000'000'000 };

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	static ull count[100][1 << 10][10];
	for(size_t i=1; i<=9; ++i)
		count[0][1 << i][i] = 1;

	for(size_t i=1; i!=N; ++i)
		for(size_t p=1; p!=1<<10; ++p)
			for(size_t j=0; j<=9; ++j){
				ull& sum = count[i][p|1<<j][j];
				if(j)sum = (sum + count[i-1][p][j-1]) % MOD;
				if(j != 9)sum = (sum + count[i-1][p][j+1]) % MOD;
			}

	ull sum = 0;
	for(size_t i=0; i!=10; ++i)
		sum = (sum + count[N-1][(1 << 10) - 1][i]) % MOD;

	cout << sum;
}