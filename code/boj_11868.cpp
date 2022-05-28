/*
    님 게임 2
    https://www.acmicpc.net/problem/11868
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  size_t n;
  cin >> n;

  size_t g = 0;
  size_t p;
  while(cin >> p) g ^= p;

  if(g) cout << "koosaga";
  else cout << "cubelover";
}