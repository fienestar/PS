/*
    칠리소스
    https://www.acmicpc.net/problem/20548
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 998'244'353;
ll pw[22], cnt, x;
vector<ll> ans;
void dfs(ll lev, ll sum) {
	if (lev == 13) {
		if (sum != 0) {
			ans.push_back(sum);
		}
		return;
	}
	dfs(lev + 1, sum);
	dfs(lev + 1, sum + pw[lev]);
	dfs(lev + 1, sum + 2 * pw[lev]);
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> x;
	pw[0] = 1;
	for (int i = 1; i <= 13; i++) {
		pw[i] = pw[i - 1] * 7;
	}
	dfs(0, 0);

	sort(all(ans));
	for (int i = 0; i < ans.size(); i++) {
		if (x == ans[i]) {
			cout << i + 1;
			break;
		}
	}
}