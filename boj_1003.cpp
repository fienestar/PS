/*
    피보나치 함수
    https://www.acmicpc.net/problem/1003
*/
#include <iostream>

using namespace std;

size_t fibo(size_t n)
{
    static size_t memo[64];
    if(n<=1)return n;
    else if(memo[n])return memo[n];
    else return memo[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
   size_t T,N;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> T;
   while(T--){
      cin >> N;
      if(N)cout << fibo(N-1) << " " << fibo(N);
      else cout << "1 0";
      cout << "\n";
   }
}