/*
    문자열의 주기 예측
    https://www.acmicpc.net/problem/1787
*/
#include <bits/stdc++.h>

using namespace std;

vector<size_t> make_pi(const string& P)
{
	vector<size_t> pi(P.size());
	size_t j = 0;

	for(size_t i=1; i!=P.size(); ++i){
		while(j && P[i] != P[j])
			j = pi[j-1];

		if(P[i] == P[j])
			pi[i] = ++j;
	}

	return pi;
	
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t n;
	string S;
	cin >> n >> S;

	auto fail = make_pi(S);
	vector<size_t> P(n);
	size_t sum = 0;
	for(size_t i=0; i!=n; ++i){
		auto& now = P[i];
		if(fail[fail[i]-1])
			now = P[fail[i]-1];
		else
			now = fail[i];

		if(now >= 1 && now*2 <= i+1)
			sum += i+1-now;
	}

	cout << sum;
}