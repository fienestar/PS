/*
    카드 역배치
    https://www.acmicpc.net/problem/10804
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<size_t> v(20);
	for(size_t i=0; i!=20; ++i)
		v[i] = i+1;

	for(size_t i=0; i!=10; ++i){
		size_t b, e;
		cin >> b >> e;
		--b;
		while(b<e)
			swap(v[b++],v[--e]);
	}

	for(auto& c:v)
		cout << c << " ";
}