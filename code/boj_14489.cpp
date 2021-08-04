/*
    치킨 두 마리 (...)
    https://www.acmicpc.net/problem/14489
*/
#include <iostream>

int main()
{
    size_t A,B,C;
    std::cin >> A >> B >> C;
    C<<=1;
    A+=B;
    if(C <= A)
        std::cout << A-C;
    else
        std::cout << A;
}