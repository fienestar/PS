/*
    수열과 쿼리 22
    https://www.acmicpc.net/problem/16978
*/
#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);

  size_t N;
  cin >> N;

  size_t P = 1;
  while(P < N)P <<= 1;

  vector<ull> seg(P << 1);
  for(size_t i=0; i!=N; ++i)
    cin >> seg[P+i];

  for(size_t i=P; --i;)
    seg[i] = seg[i<<1]+seg[i<<1|1];

  size_t M;
  cin >> M;

  struct Query{
    size_t index,op,k,i,j;
    ull v;
  };

  vector<Query> queries(M);
  size_t k = 0;
  for(size_t i=0; i!=M; ++i){
    auto& query = queries[i];
    query.index = i;
    cin >> query.op;

    if(query.op == 1){
      cin >> query.i >> query.v;
      query.k = ++k;
    }else{
      cin >> query.k >> query.i >> query.j;
    }

    --query.i;
  }

  sort(begin(queries), end(queries), [&](auto& a, auto& b){
    if(a.k == b.k)
      return a.op < b.op;
    return a.k < b.k;
  });

  vector<ull> results(M,-1);
  for(auto& [index,op,k,i,j,v]:queries){
    i += P;
    j += P;

    if(op == 1){
      seg[i] = v;
      while(i >>= 1)
        seg[i] = seg[i<<1]+seg[i<<1|1];
    }else{
      ull sum = 0;
      while(i < j){
        if(i&1)sum += seg[i++];
        if(j&1)sum += seg[--j];

        i>>=1; j>>=1;
      }

      results[index] = sum;
    }
  }

  for(auto& result:results)
    if(result != -1)
      cout << result << "\n";
}