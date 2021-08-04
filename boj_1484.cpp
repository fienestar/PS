/*
    다이어트
    https://www.acmicpc.net/problem/1484
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	using ull = unsigned long long;
	ull G;
	cin >> G;
	
	ull s,e;
	s = e = 1;
	auto get = [&](){return e*e - s*s;};
	size_t result_count = 0;

	while(s*s <= 1llu << 50){
		if(get() <= G)e++;
		else s++;

		if(get() == G){
			cout << e << "\n";
			++result_count;
		}
	}

	if(result_count == 0)
		cout << -1;
}