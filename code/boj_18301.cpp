/*
    Rats
    https://www.acmicpc.net/problem/18301
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t n1, n2, n12;
	cin >> n1 >> n2 >> n12;
	cout << (n1+1)*(n2+1)/(n12+1)-1;
}