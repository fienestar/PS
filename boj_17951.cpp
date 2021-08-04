/*
    흩날리는 시험지 속에서 내 평점이 느껴진거야
    https://www.acmicpc.net/problem/17951
*/
#include <bits/stdc++.h>

using namespace std;
using T = int;

class VI
{
	T _N;
public:
	static function<T(T)> eval;
	VI(T N):_N(N) {}
	auto operator*() { return eval(_N); }
	operator T&() { return _N; }

	using iterator_category = random_access_iterator_tag;
	using difference_type   = T;
	using value_type	= T;
	using pointer	        = T*;
	using reference         = T&;
};

function<T(T)> VI::eval = [](T n){return n;};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t N,K;
	cin >> N >> K;

	vector<T> X(N + 1);
	for(size_t i=1; i<=N; ++i){
		cin >> X[i];
		X[i] += X[i-1];
	}

	VI::eval = [&](T n){
		auto begin_iter = X.begin();
		T begin_sum = 0;
		size_t k = 0;
		n = -n;

		while(true){
			begin_iter = lower_bound(begin_iter, X.end(), n + begin_sum);

			if(begin_iter == X.end())
				return false;

			begin_sum = *begin_iter++;
			++k;

			if(k >= K)
				return true;
		}
	};

	cout << -lower_bound(VI(-2000000),VI(0),1);
}