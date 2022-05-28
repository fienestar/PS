/*
    님 게임 3
    https://www.acmicpc.net/problem/16895
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  size_t n;
  cin >> n;

  vector<size_t> P(n);
  size_t g = 0;
  for(auto& p:P){
    cin >> p;
    g ^= p;
  }

  size_t sum = 0;
  for(size_t i=0; i!=n; ++i)
    for(size_t j=1; j<=P[i]; ++j){
      g ^= P[i] ^ (P[i]-j);
      sum += !g;
      g ^= P[i] ^ (P[i]-j);
    }

  cout << sum;
}