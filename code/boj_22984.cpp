/*
    반짝반짝 2
    https://www.acmicpc.net/problem/22984
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	size_t N;
	cin >> N;

	vector<double> v(N);
	double sum = 0;
	for(auto& c:v){
		cin >> c;
		sum += c;
	}

	for(size_t i=1; i!=N; ++i)
		sum += (1-v[i])*v[i-1] + (1-v[i-1])*v[i];

	cout.precision(15);
	cout << fixed << sum;
}