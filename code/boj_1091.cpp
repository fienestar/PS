/*
    카드 섞기
    https://www.acmicpc.net/problem/1091
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<size_t> P(N);
	for(auto& c:P)
		cin >> c;

	vector<size_t> S(N);
	for(auto& c:S)
		cin >> c;

	auto check = [N](const vector<size_t>& res){
		for(size_t i=0; i!=N; ++i)
			if(res[i] != i%3)
				return false;
		return true;
	};

	vector<size_t> res(N);
	size_t i;
	for(i=0; i!=1000000; ++i){
		if(check(P))break;
		for(size_t j=0; j!=N; ++j)
			res[S[j]] = P[j];
		P = move(res);
		res.~vector<size_t>();
		new (&res)vector<size_t>(N);
	}

	if(i == 1000000)
		cout << -1;
	else
		cout << i;
}