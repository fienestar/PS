/*
    님 게임 홀짝
    https://www.acmicpc.net/problem/11871
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
  while(cin >> p)
    if(p&1) g ^= p/2+1;
    else g ^= p/2-1;

  if(g)cout << "koosaga";
  else cout << "cubelover";
}