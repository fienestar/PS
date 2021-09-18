/*
    🐜 기적의 매매법 🐜
    https://www.acmicpc.net/problem/20546
*/
/*#include <bits/stdc++.h>
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
}*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(v) v.begin(), v.end()
const ll MX = 101010;
const ll INF = 9e15;
const ll MOD = 998'244'353;

int n;
int arr[15];

int lvalue, rvalue; // 주식수
int lremain, rremain; //돈

int main() 
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 14; ++i)
		cin >> arr[i];

	lremain = rremain = n;
	for (int i = 0; i < 14; ++i) {
		if (lremain >= arr[i]) {
			lvalue += lremain / arr[i];
			lremain -= lremain / arr[i] * arr[i];
		}
	}

	for (int i = 3; i < 14; ++i) {
		if (arr[i] > arr[i - 1] && arr[i - 1] > arr[i - 2] && arr[i - 2] > arr[i - 3]) {
			rremain += rvalue * arr[i];
			rvalue = 0;
		}
		else if (arr[i] < arr[i - 1] && arr[i - 1] < arr[i - 2] && arr[i - 2] < arr[i - 3] && rremain >= arr[i]) {
			rvalue += rremain / arr[i];
			rremain -= rremain / arr[i] * arr[i];
		}
	}

	if (lvalue * arr[13] + lremain > rvalue * arr[13] + rremain)
		cout << "BNP" << endl;
	else if (lvalue * arr[13] + lremain < rvalue * arr[13] + rremain)
		cout << "TIMING" << endl;
	else
	{
		cout << "SAMESAME" << endl;
	}
}