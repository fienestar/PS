/*
    카드게임
    https://www.acmicpc.net/problem/10801
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	vector<size_t> A(10), B(10);
	for(auto& a:A)
		cin >> a;
	for(auto& b:B)
		cin >> b;

	size_t w = 0;
	size_t d = 0;
	for(size_t i=0; i!=10; ++i){
		w += A[i] < B[i];
		d += A[i] == B[i];
	}

	if(10 - d == w*2)
		cout << "D";
	else if(10 - d > w*2)
		cout << "A";
	else
		cout << "B";
}