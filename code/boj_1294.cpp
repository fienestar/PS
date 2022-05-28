/*
    문자열 장식
    https://www.acmicpc.net/problem/1294
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  size_t N;
  cin >> N;

  vector<string> words(N);
  for(auto& word:words)
    cin >> word;

  priority_queue pq([](auto& lhs, auto& rhs){
    size_t i;
    for(i=0; lhs[i] && rhs[i]; ++i)
      if(lhs[i] != rhs[i])
        return lhs[i] > rhs[i];
    if(lhs[i] && rhs[i]) return false;
    return !lhs[i];
  }, words);

  while(!pq.empty()){
    auto s = pq.top();
    pq.pop();
    if(s.size() != 1)
      pq.emplace(s.substr(1));
    cout << s[0];
  }
}