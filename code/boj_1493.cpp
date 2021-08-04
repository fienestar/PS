/*
    박스 채우기
    https://www.acmicpc.net/problem/1493
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	using ull = unsigned long long;

	ull len, wid, hei;
	cin >> len >> wid >> hei;

	ull N;
	cin >> N;

	vector<pair<ull,ull>> cubes(N);
	for(auto& cube:cubes){
		cin >> cube.first >> cube.second;
		cube.first = 1 << cube.first;
	}

	sort(cubes.rbegin(), cubes.rend());
		
	ull cnt = 0;
	ull total = 0;
	for(auto& cube:cubes){
		ull size = cube.first * cube.first * cube.first;
		ull use = min((len / cube.first) * (wid / cube.first) * (hei / cube.first) - total / size, cube.second);
		total += size * use;
		cnt += use; 
	}

	if(total == len * wid * hei)
		cout << cnt;
	else
		cout << -1;
}