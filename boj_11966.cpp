/*
    2의 제곱인가?
    https://www.acmicpc.net/problem/11966
*/
#include <iostream>

int main()
{
    size_t N;
    std::cin >> N;
    while(N!=1)
	if(N&1)break;
        else N>>=1;
    std::cout << (N==1);
}