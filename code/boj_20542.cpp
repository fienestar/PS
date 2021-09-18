/*
    받아쓰기
    https://www.acmicpc.net/problem/20542
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 998'244'353;
ll n, m;
string s1, s2;
vector < vector<ll> >dp;
ll sol(ll x, ll y) {
	if(x == n && y == m) return 0;
	ll& ret = dp[x][y];
	if(ret != -1) return ret;
	ret = INF;
	if (x < n && y < m) {
		ll chk = 1;
		if(s1[x] == s2[y]) chk = 0;
		if(s1[x] == 'i' && (s2[y] == 'j' || s2[y] == 'l')) chk = 0;
		if(s1[x] == 'v' && (s2[y] == 'w')) chk = 0;
		ret = min(sol(x + 1, y + 1) + chk, ret);
	}
	if(y < m) ret = min(ret, sol(x, y + 1) + 1);
	if(x < n) ret = min(ret, sol(x + 1, y) + 1);
	return ret;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	cin >> s1 >> s2;
	dp.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i].resize(m + 1);
		for (int j = 0; j <= m; j++) {
			dp[i][j] = -1;
		}
	}
	cout << sol(0, 0);
}