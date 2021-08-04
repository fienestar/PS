/*
    사과와 바나나
    https://www.acmicpc.net/problem/3114
*/
#include <bits/stdc++.h>

using namespace std;

struct pab
{
	size_t a,b;
	pab(): a(0), b(0) {}
	pab(size_t _a,size_t _b): a(_a), b(_b) {}
	pab operator+(const pab& oth) const{
		return pab(a+oth.a,b+oth.b);
	}
	pab operator-(const pab& oth) const{
		return pab(a-oth.a,b-oth.b);
	}
	size_t operator+() const{
		return a+b;
	}
	bool operator<(const pab& oth) const{
		return +*this < +oth;
	}
	pab& operator+=(const pab& oth){
		a += oth.a; b += oth.b; return *this;
	}
	pab& operator-=(const pab& oth){
		a -= oth.a; b -= oth.b; return *this;
	}
};

int main()
{
	size_t R, C;
	cin >> R >> C;

	static pab _sum[1501][1501] = {};
	auto& sum = (pab(&)[1500][1500])_sum[1][1];

	for(size_t i=0; i!=R; ++i)
		for(size_t j=0; j!=C; ++j){
			char c;
			cin >> c;
			if(c == 'B')cin >> sum[i][j].b;
			else cin >> sum[i][j].a;

			sum[i][j] += sum[i  ][j-1];
			sum[i][j] += sum[i-1][j  ];
			sum[i][j] -= sum[i-1][j-1];
		}

	static pab dp[1501][1501] = {};

	for(size_t i=R; --i;)
		for(size_t j=C; --j;){
			for(size_t k=0; k!=2; ++k){
				static int di[] = {-1,  0};
				static int dj[] = { 0, -1};

				size_t mi = i + di[k];
				size_t mj = j + dj[k];

				pab get = sum[i+di[k^1]][j+dj[k^1]] - sum[i-1][j-1];

				if(k)get.a = 0;
				else get.b = 0;

				dp[mi][mj] = max(dp[mi][mj], get + dp[i][j]);
			}

			pab get((sum[i][j-1] - sum[i-1][j-1]).a,(sum[i-1][j] - sum[i-1][j-1]).b);

			dp[i-1][j-1] = max(dp[i-1][j-1], get + dp[i][j]);
		}

	pab result = dp[0][0];

	for(size_t i=1; i!=R; ++i)
		result = max(result, dp[i][0]);

	for(size_t j=1; j!=C; ++j)
		result = max(result, dp[0][j]);

	cout << +result;
}