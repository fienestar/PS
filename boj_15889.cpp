/*
    호 안에 수류탄이야!!
    https://www.acmicpc.net/problem/15889
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	size_t N;
	cin >> N;

	vector<pair<size_t,size_t>> players(N);
	for(auto& player:players)
		cin >> player.first;

	for(auto& player:players)
		cin >> player.second;

	sort(players.begin(), players.end());

	size_t farthest = 0;
	for(auto& player:players)
		if(player.first <= farthest)
			farthest = max(farthest, player.first + player.second);

	if(players[N-1].first <= farthest)
		cout << "권병장님, 중대장님이 찾으십니다";
	else
		cout << "엄마 나 전역 늦어질 것 같아";
}