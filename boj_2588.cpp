/*
    곱셈
    https://www.acmicpc.net/problem/2588
*/
#include <iostream>

using namespace std;

int main()
{
    int n[2];
    cin >> n[0] >> n[1];
    cout << n[1]%10*n[0] << "\n" << n[1]/10%10*n[0] << "\n" << n[1]/100%10*n[0] << "\n" << n[1]*n[0];
}