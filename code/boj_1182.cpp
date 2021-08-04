/*
    부분수열의 합
    https://www.acmicpc.net/problem/1182
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	int S;
	cin >> S;

	vector<int> I(N);
	for(auto& i:I)
		cin >> i;

	size_t count = 0;
	function<void(size_t,int)> dfs = [&](size_t i, int sum){
		if(i == N){
			count += (sum == S);
			return;
		}

		dfs(i+1,sum);
		dfs(i+1,sum+I[i]);
	};

	dfs(0,0);

	cout << count - (S==0);
}