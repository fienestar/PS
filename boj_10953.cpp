/*
    A+B - 6
    https://www.acmicpc.net/problem/10953
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,A,B;
    scanf("%d",&T);
    while(T--){
	scanf("%d,%d",&A,&B);
	printf("%d\n",A+B);
    }
}