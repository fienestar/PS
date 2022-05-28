/*
    님 게임 나누기
    https://www.acmicpc.net/problem/11872
*/
#include <bits/stdc++.h>

using namespace std;

size_t grundy(size_t p)
{
	switch(p%4){
		case 0:
			return p-1;
		case 1:
		case 2:
			return p;
		case 3:
			return p+1;
	}
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t p;
	cin >> p;

	size_t g = 0;
	while (cin >> p)
		g ^= grundy(p);

	if (g)
		cout << "koosaga";
	else
		cout << "cubelover";
}