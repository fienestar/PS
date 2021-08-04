/*
    9진수
    https://www.acmicpc.net/problem/14491
*/
#include <iostream>

int main()
{
    char buf[64];
    char * pos = buf+63;
    size_t N;
    *pos = '\0';
    std::cin >> N;
    do
        *--pos = '0' + N % 9;
    while(N/=9);
    puts(pos);
}