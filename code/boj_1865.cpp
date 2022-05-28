/*
    웜홀
    https://www.acmicpc.net/problem/1865
*/
#include <bits/stdc++.h>

using namespace std;

void solve()
{
  size_t N,M,W;
  cin >> N >> M >> W;

  static int edge[500][500];
  memset(edge, 0x3f, sizeof(edge));
  int inf;
  memset(&inf, 0x3f, sizeof(inf));

  size_t S, E;
  int T;
  while(M--){
    cin >> S >> E >> T;
    --S; --E;

    edge[S][E] = min(edge[S][E], T);
    edge[E][S] = min(edge[E][S], T);
  }

  while(W--){
    cin >> S >> E >> T;
    --S; --E;
    edge[S][E] = min(edge[S][E], -T);
  }

  for(size_t k=0; k!=N; ++k)
    for(size_t i=0; i!=N; ++i)
      for(size_t j=0; j!=N; ++j)
        edge[i][j] = min(edge[i][j], edge[i][k]+edge[k][j]);

  for(size_t i=0; i!=N; ++i)
    if(edge[i][i] != -1 && (int)edge[i][i] < 0)
      return (void)(cout << "YES\n");

  cout << "NO\n";
}

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  size_t TC;

  cin >> TC;
  while(TC--) solve();
}