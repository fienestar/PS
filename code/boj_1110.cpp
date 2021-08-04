/*
    더하기 사이클
    https://www.acmicpc.net/problem/1110
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	size_t end = N;
	size_t len = 0;
	do{
		N = (N%10)*10 + (N/10+N)%10;
		++len;
	}while(N != end);

	cout << len;
}