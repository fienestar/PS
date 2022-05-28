/*
    Computer Purchase
    https://www.acmicpc.net/problem/6799
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	vector<pair<int,string>> v(n);
	for(auto& [c,name]:v){
		int R, S, D;
		cin >> name >> R >> S >> D;

		c = -(2*R + 3*S + D);
	}

	sort(v.begin(), v.end());

	for(size_t i=0; i!=n && i!=2; ++i)
		cout << v[i].second << "\n";
}