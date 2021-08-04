/*
    보물
    https://www.acmicpc.net/problem/1026
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,N) for(std::size_t i=0;i!=N;++i)
#define all(v) v.begin(),v.end()

int main()
{
    std::size_t N,S=0;
    std::vector<std::size_t> A,B;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> N;
    A.resize(N); B.resize(N);
    loop(i,N)std::cin >> A[i];
    loop(i,N)std::cin >> B[i];
    std::sort(all(A)); std::sort(all(B));
    loop(i,N)S+=A[i]*B[N-i-1];
    std::cout << S;
}