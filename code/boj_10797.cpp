/*
    10부제
    https://www.acmicpc.net/problem/10797
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t n;
	cin >> n;

	size_t cnt = 0;
	for(size_t i=0; i!=5; ++i){
		size_t car;
		cin >> car;
		cnt += car%10 == n%10;
	}

	cout << cnt;
}