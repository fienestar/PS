/*
    앞뒤가 맞는 수열
    https://www.acmicpc.net/problem/16570
*/
#include <bits/stdc++.h>

using namespace std;

template <class T>
vector<size_t> make_pi(const vector<T>& P)
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

	size_t N;
	cin >> N;

	vector<int> A(N);
	for(size_t i=N; i--;)
		cin >> A[i];

	auto pi = make_pi(A);
	size_t M = 0;
	size_t M_count = 0;
	for(auto& c:pi){
		if(M < c){
			M = c;
			M_count = 0;
		}
		M_count += c == M;
	}

	if(M)
		cout << M << " " << M_count;
	else
		cout << "-1";
}