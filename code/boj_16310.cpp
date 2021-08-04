/*
    Game Night
    https://www.acmicpc.net/problem/16310
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	string teams;
	cin >> teams;

	auto count = [&](size_t b, size_t e, char c){
		return (size_t)std::count(teams.begin() + b, teams.begin() + e, c);
	};

	auto get = [&](size_t i){
		return teams[i % N];
	};

	auto sum = [](size_t (&arr)[3]){
		return arr[0] + arr[1] + arr[2];
	};

	size_t a = count(0, N, 'A');
	size_t b = count(0, N, 'B');
	size_t c = count(0, N, 'C');

	size_t abc[] = {
		count(  0,  a,'A'),
		count(  a,a+b,'B'),
		count(a+b,  N,'C')
	};

	size_t acb[] = {
		count(0,a,'A'),
		count(a,a+c,'C'),
		count(a+c,N,'B')
	};

	size_t M = max(sum(abc), sum(acb));

	for(size_t i=0; i!=N; ++i){
		char ch;

		ch = get(i);
		if(ch == 'A') --abc[0], --acb[0];
		else if(ch == 'B') ++acb[2];
		else ++abc[2];

		ch = get(i+a);
		if(ch == 'A') ++abc[0], ++acb[0];
		else if(ch == 'B') --abc[1];
		else --acb[2];

		ch = get(i+a+b);
		if(ch == 'B') ++abc[1];
		else if(ch == 'C') --abc[2];

		ch = get(i+a+c);
		if(ch == 'B') --acb[2];
		else if(ch == 'C') ++acb[1];

		M = max({M, sum(abc), sum(acb)});
	}

	cout << N - M;
}