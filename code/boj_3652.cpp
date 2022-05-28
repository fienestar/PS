/*
    새트리
    https://www.acmicpc.net/problem/3652
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  struct ab_t{
    size_t a,b;
  };
  ab_t inf = {-1u/2,-1u/2};

  auto gcd = [&](ab_t v){
    auto gcd = std::gcd(v.a, v.b);
    return ab_t{v.a/gcd, v.b/gcd};
  };

  auto f = [&](ab_t v)->ab_t{
    v = {v.b,v.a};
    if(v.a <= v.b) return inf;
    v.a -= v.b;
    return gcd(v);
  };

  auto g = [&](ab_t v)->ab_t{
    if(v.a <= v.b) return inf;
    v.a -= v.b;
    return gcd({v.b,v.a});
  };

  auto sum = [](ab_t v){
    return v.a+v.b;
  };

  ab_t ab;
  cin >> ab.a >> (char&)ab.b >> ab.b;

  while(ab.a * ab.b != 1){
    auto left = f(ab);
    auto right = g(ab);

    if(sum(right) > sum(left)){
      cout << 'L';
      ab = left;
    }else{
      cout << 'R';
      ab = right;
    }
  }
}