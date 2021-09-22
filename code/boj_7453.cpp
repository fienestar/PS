/*
    합이 0인 네 정수
    https://www.acmicpc.net/problem/7453
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	static tuple<int,int,int,int> abcd[4000];
	for(size_t i=0; i!=N; ++i)
		if(auto& [a,b,c,d] = abcd[i]; true)
			cin >> a >> b >> c >> d;

	static int ab[4000*4000];
	static int cd[4000*4000];
	for(size_t i=0; i!=N; ++i)
		for(size_t j=0; j!=N; ++j){
			ab[i*N+j] = get<0>(abcd[i]) + get<1>(abcd[j]);
			cd[i*N+j] = get<2>(abcd[i]) + get<3>(abcd[j]);
		}

	sort(ab, ab+N*N);
	sort(cd, cd+N*N);

	size_t j=N*N-1;
	size_t ans = 0;
	size_t before = 0;
	for(size_t i=0; i!=N*N; ++i){
		if(i && ab[i] == ab[i-1]){
			ans += before;
			continue;
		}

		before = 0;

		while(cd[j] + ab[i] > 0 && j < N*N)
			--j;

		while(cd[j] + ab[i] == 0 && j < N*N){
			++ans;
			++before;
			--j;
		}
	}

	cout << ans;
}