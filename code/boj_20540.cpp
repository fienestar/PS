/*
    연길이의 이상형
    https://www.acmicpc.net/problem/20540
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 998'244'353;
string ans;
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	if (s[0] == 'E') ans += 'I';
	else ans += 'E';
	if (s[1] == 'S') ans += 'N';
	else ans += 'S';
	if (s[2] == 'T') ans += 'F';
	else ans += 'T';
	if (s[3] == 'J') ans += 'P';
	else ans += 'J';
	cout << ans;
}