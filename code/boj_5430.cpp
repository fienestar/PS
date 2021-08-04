/*
    AC
    https://www.acmicpc.net/problem/5430
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	string f;
	cin >> f;

	size_t n;
	cin >> n;

	vector<int> v(n);
	char ch;
	if(n == 0)cin >> ch;
	for(auto& c:v)
		cin >> ch >> c;
	cin >> ch;

	size_t begin = 0;
	size_t end = n;
	bool reversed = false;

	for(auto c:f)
		if(c == 'R')
			reversed ^= 1;
		else{
			if(reversed)
				--end;
			else
				++begin;

			if(begin > end){
				cout << "error\n";
				return;
			}
		}

	if(begin == end)
		cout << "[]\n";
	else if(reversed){
		cout << "[";
		for(size_t i=end-1; i != begin; --i)
			cout << v[i] << ",";
		cout << v[begin] << "]\n";
	}else{
		cout << "[";
		for(size_t i=begin; i+1!=end; ++i)
			cout << v[i] << ",";
		cout << v[end-1] << "]\n";
	}
}

int main()
{
	size_t T;
	cin >> T;

	while(T--)
		solve();
}