/*
    폭탄 던지는 태영이
    https://www.acmicpc.net/problem/20543
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 998'244'353;

#define endl '\n'

int n, m;
ll arr[2005][2005];
ll ans[2005][2005];

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int j = m / 2; j < n - m / 2; ++j) {
		ll sum = 0;
		for (int i = m / 2; i < n - m / 2; ++i) {
			ans[i][j] = -arr[i - m / 2][j - m / 2] - sum;
			sum += ans[i][j];
			if (i - (m - 1) > 0)
				sum -= ans[i - (m - 1)][j];
		}
	}

	for (int i = m / 2; i < n - m / 2; ++i) {
		ll sum = 0;
		for (int j = m / 2; j < n - m / 2; ++j) {
			ans[i][j] -= sum;
			sum += ans[i][j];
			if (j - (m - 1) > 0)
				sum -= ans[i][j - (m - 1)];
		}
	}

	for (int i = 0; i < n; ++i,cout<<endl)
		for (int j = 0; j < n; ++j)
			cout << ans[i][j] << ' ';
}