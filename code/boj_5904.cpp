/*
    Moo 게임
    https://www.acmicpc.net/problem/5904
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	while(true){
		size_t i;
		size_t j;

		for(i=0, j=2; i*2 + 1+j < N; (i=i*2+1+j), ++j);

		N -= i;

		if(N == 1){
			cout << "m";
			break;
		}
		--N;

		if(N <= j){
			cout << "o";
			break;
		}
		N -= j;
	}
}