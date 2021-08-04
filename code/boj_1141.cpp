/*
    접두사
    https://www.acmicpc.net/problem/1141
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	vector<string> v(N);
	for(auto& c:v)
		cin >> c;

	sort(v.rbegin(), v.rend());

	size_t count = 1;
	size_t last = 0;
	for(size_t i=1; i!=N; ++i)
		if(v[i].size() > v[last].size() || v[last].substr(0, v[i].size()) != v[i]){
			last = i;
			++count;
		}

	cout << count;
}