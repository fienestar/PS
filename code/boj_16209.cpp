/*
    수열 섞기
    https://www.acmicpc.net/problem/16209
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	using ll = long long;

	cin.tie(nullptr)->sync_with_stdio(false);

	size_t N;
	cin >> N;

	vector<ll> n;
	vector<ll> p;

	n.reserve(N);
	p.reserve(N);

	for(size_t i=0; i!=N; ++i){
		ll t;
		cin >> t;

		if(t > 0)
			p.push_back(t);
		else
			n.push_back(t);
	}

	sort(p.rbegin(), p.rend());
	sort(n.begin(), n.end());

	auto push = [](vector<ll>& v, deque<ll>& d){
		size_t i=0;
		d.push_front(v[i++]);

		while(i != v.size())
			if(d.front()*v[i] > d.back()*v[i])
				d.push_front(v[i++]);
			else
				d.push_back(v[i++]);
	};

	deque<ll> pd;
	deque<ll> nd;

	if(!p.size()){
		push(n, nd);
		for(size_t i=0; i!=N; ++i)cout << nd[i] << " ";
	}else if(!n.size()){
		push(p, pd);
		for(size_t i=0; i!=N; ++i)cout << pd[i] << " ";
	}else{
		push(n, nd);
		push(p, pd);
		if(pd.front() < pd.back())
			for(size_t i=pd.size(); i--;)cout << pd[i] << " ";
		else
			for(size_t i=0; i!=pd.size(); ++i)cout << pd[i] << " ";

		if(nd.front() < nd.back())
			for(size_t i=nd.size(); i--;)cout << nd[i] << " ";
		else
			for(size_t i=0; i!=nd.size(); ++i)cout << nd[i] << " ";
	}
}