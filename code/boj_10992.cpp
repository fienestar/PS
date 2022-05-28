/*
    별 찍기 - 17
    https://www.acmicpc.net/problem/10992
*/
#include <bits/stdc++.h>

using namespace std;

struct chars{
	char c;
	size_t n;
};
ostream& operator<<(ostream& os, const chars& c)
{
	size_t N = c.n;
	while(N--)os << c.c;
	return os;
}

int main()
{
	size_t N;
	cin >> N;

	cout << chars{' ',N-1} << "*\n";
	for(size_t i=1; i<N-1; ++i)
		cout << chars{' ',N-i-1} << '*' << chars{' ',i*2-1} << "*\n";
	if(N!=1)cout << chars{'*',N*2-1};
}